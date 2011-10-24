
#include "Connector.h"


Connector::Connector() : m_username(""), m_passSara(""), m_passvnc(""), m_hours(""), m_minutes(""), m_seconds(""), output(new QTextEdit), process(new QProcess(this)) 
{
    setupOutputBox() ;
    connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(writeToOutput())) ;
}

Connector::~Connector() {}

void Connector::setupOutputBox() {
    
    QPalette p = output->palette() ;
    QFont mono("Inconsolata", 12) ;
    mono.setStyleStrategy(QFont::PreferAntialias);
    p.setColor(QPalette::Base, Qt::black) ;
    output->setReadOnly(true) ;
    output->setPalette(p) ;
    output->setTextColor(Qt::green) ;

    output->append("*******Connector Output*******") ;
    output->append("\n\n") ;
}

QTextEdit *Connector::getOutput() {
    return output ;
}

/* Expect login version  
void Connector::login() {
    process->setProcessChannelMode(QProcess::MergedChannels) ;
    QString program = "./test.exp" ;
    QString arg = "test.exp" ;
    process->start(program) ;
    process->waitForStarted() ;

}
*/

void Connector::writeToOutput() {
    output->append(process->readAllStandardOutput()) ;
}

void Connector::setUsername(QString username) {
    m_username = username.toStdString() ;
    q_username = username ;
}

void Connector::setPassword(QString passSara) {
    m_passSara = passSara.toStdString() ;
    q_passSara = passSara ;
}

void Connector::setVNCPassword(QString passvnc) {
    m_passvnc = passvnc.toStdString() ;
    q_passvnc = passvnc ;
}

void Connector::setTimeHours(QString hours) {
    m_hours = hours.toStdString() ;
}

void Connector::setTimeMinutes(QString minutes) {
    m_minutes = minutes.toStdString() ;
}

void Connector::setTimeSeconds(QString seconds) {
    m_seconds = seconds.toStdString() ;
}

// libssh login version
void Connector::libsshLogin() {
// the verbosity of the ssh log

	int verbosity = SSH_LOG_PROTOCOL;
	int port = 22; // the port used (22 is default)
	
	sshSession = ssh_new() ; 

	if (sshSession == NULL){
		exit(-1);
    }

    output->append("Initializing connection with RVS cluster...") ;	

	/*Setting the options of this connection*/
	ssh_options_set(sshSession, SSH_OPTIONS_HOST, "rvs.sara.nl") ;
	ssh_options_set(sshSession, SSH_OPTIONS_USER, m_username.c_str()) ; // TODO, make the username and host flexibile
	ssh_options_set(sshSession, SSH_OPTIONS_LOG_VERBOSITY, &verbosity);
	ssh_options_set(sshSession, SSH_OPTIONS_PORT, &port);
	
    output->append("\n") ;

	/*Connecting*/
	int response = ssh_connect(sshSession);
	if (response != SSH_OK) {
        output->append("Error connecting to the RVS") ;
        output->append(ssh_get_error(sshSession)) ;
		ssh_free(sshSession);
		exit(-1);
	}

	// TODO check if the server is known!
	
	response = ssh_userauth_password(sshSession, NULL, m_passSara.c_str());
	if (response != SSH_AUTH_SUCCESS){
        output->append("ERROR: Auth. failed") ;
        output->append(ssh_get_error(sshSession)) ;
		ssh_free(sshSession);
		exit(-1);
	} else {
        output->append("Authorization succesful!") ;
	}
    output->append("\n") ;
    output->append("Waiting for VNC connection...") ;
    qApp->processEvents() ;
}

int Connector::startVNCSession(string hours, string minutes, string seconds) {
    std::string command = "/usr/sara/bin/rvs_vnc " + m_hours + ":" + m_minutes + ":" + m_seconds ;
	
	// creates a new channel
	channel = ssh_channel_new(sshSession);
	if (channel == NULL) {
		output->append("ERROR: Unable to set up channel between host and client...") ; 
		exit(-1) ; 
	}
	
	// links the channel to the current ssh session
	int response = ssh_channel_open_session(channel);
	if (response != SSH_OK) {
		ssh_channel_free(channel);
		output->append("ERROR: Unable to set up channel between host and client...") ; 
		exit(-1) ;
	}
	
	// Executes the command
	output->append("A new channel has been opened.") ; 
	response = ssh_channel_request_exec(channel, command.c_str());
	if (response != SSH_OK){
		output->append("ERROR: Unable to execute the command on the host...") ; 
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
			output->append("ERROR: buffer to small to read all data") ;
			break ; 
		}
		nbytes = ssh_channel_read(channel, buffer, sizeof(buffer), 0);
	}
	
	if (nbytes < 0)
	{
		ssh_channel_close(channel);
		ssh_channel_free(channel);
		output->append("ERROR: buffer to small to read all data") ; 
	}
	
	/*Check whether the new VNC session is queued */
	std::string bufferOutput = buffer ; 
	size_t found = bufferOutput.find("v42-") ; 
    std::string strNode (bufferOutput, found + 4, 2) ; 
    QString strNode2 = QString::fromStdString(strNode) ;
    QString status = QString("Connection to node %1").arg(strNode2) ;
	output->append(status) ; 
	int node = atoi(strNode.c_str());
    //int node = strNode.toInt() ;
		
	// Closes the channel
	ssh_channel_send_eof(channel);
	ssh_channel_close(channel);		

    output->append("Loading VNC session...") ;
    qApp->processEvents() ;
    return node ;
}

void Connector::logout () {
	output->append("Logging out...") ; 
	if (channel != NULL) {
		ssh_channel_close(channel);
		ssh_channel_free(channel);
		output->append("Channel is closed...") ; 
	}
	ssh_disconnect(sshSession);
	ssh_free (sshSession) ;
	output->append("Logged out succesfully...") ; 
}
    
void Connector::connectToVNCServer(int node) {
    process->setProcessChannelMode(QProcess::MergedChannels) ;
    QString program = "./vncviewer.exp" ;
    process->start(program, QStringList() << q_passSara << q_passvnc << "rvs.sara.nl" << q_username << QString::number(node)) ;
    process->waitForStarted() ;
    qApp->processEvents() ;
}
