/*
 *  Connector.h
 *  
 * The Connector-class has the following functionality:
 *		1. It connects to the RVS-cluster, given a username and corresponding password
 *		2. Sets up a channel
 *		3. Stands in the queue for a job with a given wall-clock time
 *
 * Project: Micro-CT scans of Corals
 * Author: Louis Dijkstra
 * Date: October 2011
 */

#include "Connector.h"

/*
 * The constructor of connector. 
 */
Connector::Connector ()
{ 
	; 
}

/*
 * The constructor of connector. 
 *
 * Args:
 *		- the username
 *		- corresponding password
 */
Connector::Connector (std::string _username, std::string _password, std::string _vncPassword)
{ 
	username = _username ; 
	password = _password ; 
	vncPassword = _vncPassword ; 
}

/*
 * The destructor of connector. 
 */
Connector::~Connector () 
{ ; 
}

/*
 * Logs the user in to the RVS cluster. 
 *
 * NOTE! Make sure to log out - see function Connector::logout()
 */
void Connector::login () {
	// the verbosity of the ssh log
	int verbosity = SSH_LOG_PROTOCOL;
	int port = 22; // the port used (22 is default)
	
	sshSession = ssh_new() ; 
	if (sshSession == NULL)
		exit(-1);
	
	/*Setting the options of this connection*/
	ssh_options_set(sshSession, SSH_OPTIONS_HOST, "rvs.sara.nl") ;
	ssh_options_set(sshSession, SSH_OPTIONS_USER, username.c_str()) ; // TODO, make the username and host flexibile
	ssh_options_set(sshSession, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
	ssh_options_set(sshSession, SSH_OPTIONS_PORT, &port);
	
	/*Connecting*/
	int response = ssh_connect(sshSession);
	if (response != SSH_OK) {
		printToStatusBar("Error connecting to the RVS.") ; 
		printToStatusBar(ssh_get_error(sshSession)) ; 
		ssh_free(sshSession);
		exit(-1);
	}
	
	// TODO check if the server is known!
	
	response = ssh_userauth_password(sshSession, NULL, password.c_str());
	if (response != SSH_AUTH_SUCCESS){
		printToStatusBar("ERROR: Auth. failed") ; 
		printToStatusBar(ssh_get_error(sshSession)) ;
		ssh_free(sshSession);
		exit(-1);
	} else {
		printToStatusBar("Auth. succesful!") ; 
	}
}

/*
 * Sets up the channel used for communication between the local machine and the RVS-cluster
 *
 * CURRENTLY NOT USED - might be usefull later
 */
void Connector::setUpChannel () {
	// creates a new channel
	channel = ssh_channel_new(sshSession);
	if (channel == NULL) {
		printToStatusBar("ERROR: Unable to set up channel between host and client...") ; 
		exit(-1) ; 
	}
	
	// links the channel to the current ssh session
	int response = ssh_channel_open_session(channel);
	if (response != SSH_OK) {
		ssh_channel_free(channel);
		printToStatusBar("ERROR: Unable to set up channel between host and client...") ; 
		exit(-1) ;
	}
	
	printToStatusBar("A new channel has been opened.") ; 
}


/*
 * Opens a channel, executes the given command and closes the channel again. 
 */
void Connector::executeRemoteCommand (std::string command) {
	// creates a new channel
	channel = ssh_channel_new(sshSession);
	if (channel == NULL) {
		printToStatusBar("ERROR: Unable to set up channel between host and client...") ; 
		exit(-1) ; 
	}
	
	// links the channel to the current ssh session
	int response = ssh_channel_open_session(channel);
	if (response != SSH_OK) {
		ssh_channel_free(channel);
		printToStatusBar("ERROR: Unable to set up channel between host and client...") ; 
		exit(-1) ;
	}
	
	// Executes the command
	printToStatusBar("A new channel has been opened.") ; 
	response = ssh_channel_request_exec(channel, command.c_str());
	if (response != SSH_OK){
		printToStatusBar("ERROR: Unable to execute the command on the host...") ; 
		exit(-1) ;
	}
	
	// Reading the result of the command and printing it to the status bar
	char buffer[8192];
	unsigned int nbytes;
	
	nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
	while (nbytes > 0)
	{
		if (fwrite(buffer, 1, nbytes, stdout) != nbytes)
		{
			ssh_channel_close(channel);
			ssh_channel_free(channel);
			printToStatusBar("ERROR: buffer to small to read all data") ;
			break ; 
		}
		nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
	}
	
	if (nbytes < 0)
	{
		ssh_channel_close(channel);
		ssh_channel_free(channel);
		printToStatusBar("ERROR: buffer to small to read all data") ; 
	}
	
	printToStatusBar(buffer) ; 
	ssh_channel_send_eof(channel);
	ssh_channel_close(channel);
}

/*
 * Stops the current ssh session. It disconnects and frees the allocated memory. 
 */
void Connector::logout () {
	printToStatusBar("Logging out...") ; 
	if (channel != NULL) {
		ssh_channel_close(channel);
		ssh_channel_free(channel);
		printToStatusBar("Channel is closed...") ; 
	}
	ssh_disconnect(sshSession);
	ssh_free (sshSession) ;
	printToStatusBar("Logged out succesfully...") ; 
}

/*
 * Makes a request for a new session on the RVS cluster. 
 *
 * args:
 *		h - the number of hours 
 *		m - the number of minutes
 *		s - the number of second 
 *
 */
void Connector::startVNCSession (std::string h, std::string m, std::string s) { 
	std::string command = "qsub -lwalltime=" + h + ":" + m + ":" + s + " /usr/sara/bin/vnc-session" ;
	executeRemoteCommand(command) ; 	
} 

/*
 * Returns the node where the new VNC session is being hosted. This node is important for setting up the VNC connection.
 * This routine checks several times if the new VNC session is ready by checking /usr/sara/bin/rvs_show
 * 
 * Returns:
 *		node (int) - the node on which the new vnc session runs
 */
int Connector::returnVNCNode () {
	
	int vncSessionReady = 0 ; // 1, if the VNC session is ready, otherwise 0. 
	int node = - 1; // The node on which the new VNC session started
	
	/*Check if the VNC session is ready*/
	while (vncSessionReady == 0) {
		sleep(1) ; 
		// creates a new channel
		channel = ssh_channel_new(sshSession);
		if (channel == NULL) {
			printToStatusBar("ERROR: Unable to set up channel between host and client...") ; 
			exit(-1) ; 
		}
		
		// links the channel to the current ssh session
		int response = ssh_channel_open_session(channel);
		if (response != SSH_OK) {
			ssh_channel_free(channel);
			printToStatusBar("ERROR: Unable to set up channel between host and client...") ; 
			exit(-1) ;
		}
		
		// Executes the command
		std::string command = "/usr/sara/bin/rvs_show" ;  
		response = ssh_channel_request_exec(channel, command.c_str());
		if (response != SSH_OK){
			printToStatusBar("ERROR: Unable to execute the command on the host...") ; 
			exit(-1) ;
		}
		
		// Reading the result of the command and printing it to the status bar
		char buffer[8192];
		unsigned int nbytes;
		
		nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
		while (nbytes > 0)
		{
			if (fwrite(buffer, 1, nbytes, stdout) != nbytes)
			{
				ssh_channel_close(channel);
				ssh_channel_free(channel);
				printToStatusBar("ERROR: buffer to small to read all data") ;
				break ; 
			}
			nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
		}
		
		if (nbytes < 0)
		{
			ssh_channel_close(channel);
			ssh_channel_free(channel);
			printToStatusBar("ERROR: buffer to small to read all data") ; 
		}

	    /*Check whether the new VNC session is queued */
		std::string output = buffer ; 
		size_t found = output.find(username) ; 
		
		if (found != std::string::npos) {
			printToStatusBar("New VNC Session is ready on the RVS") ; 
			vncSessionReady = 1 ; 
			/*find the node on which the VNC Session runs*/
			found = output.find("v41-", found) ; 
			std::string strNode (output, found + 4, 2);
			printToStatusBar("Connecting to node " + strNode) ; 
			node = atoi(strNode.c_str());
		}	
				
		ssh_channel_send_eof(channel);
		ssh_channel_close(channel);		
	}
	
	return node ; 
}



/*
 * Sends a folder/file to the remote RVS client from the local machine. 
 * Can be used for sending other CT scans that are currently not available there. 
 *
 * args:
 *		fileLocation - a string given information about the location of the folder/file that needs to be transfered. 
 *		resultingDirectory - a string stating in which directory the file/directory should be stored on the UNIX host.
 */
void Connector::upload (std::string fileLocation, std::string resultingDirectory) {
	printToStatusBar("Sending the file " + fileLocation + " to the directory " + resultingDirectory + " on the RVS-account") ; 
	std::string command = "./scp.exp " + password + " rvs.sara.nl " + username + " " + fileLocation + " " + resultingDirectory ;  
	system(command.c_str()) ;
	printToStatusBar("Done sending file...") ; 
}

/*
 * Connects to the newly created VNC server at the RVS. The VNC server is connected to one of the nodes available at the RVS. 
 * The number of nodes currently runs from 1 to 8. 
 *
 * The UNIX script used for this particular function expects that TurboVNC is installed on the usual location:
 *		/opt/TurboVNC/bin/vncviewer
 *
 * If this is not the case, change this!
 *
 * Possible improvements:
 *	 - automatic detection if and where TurboVNC is installed...
 *
 * args:
 *		node - the node of the RVS on which the VNC server is running (1 - 8)
 */
void Connector::connectToVNCSever (int node) {
	std::string stringNode;
	std::stringstream out;
	out << node;
	stringNode = out.str();
	
	printToStatusBar("Connecting to VNC server on the RVS cluster...") ; 
	std::string command = "./vncviewer.exp " + password + " " + vncPassword + " rvs.sara.nl " + username + " " + stringNode ; 
	system(command.c_str()) ;
	// TODO error handling? 
	printToStatusBar("Done connecting to the VNC server...") ; 
}

void Connector::printToStatusBar (std::string message) { 
	std::cout << message << std::endl; 
} // prints a message to the status bar


