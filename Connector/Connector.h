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

#include <stdlib.h>
#include <stdio.h> 
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <errno.h>
#include <string.h>
#include <string>
#include <cstdlib>
#include <sstream>

#include "libssh/libssh.h"

class Connector  
{
public:
	Connector() ; // Ctor
	Connector (std::string _username, std::string _password, std::string _vncPassword) ; 
	~Connector() ; // Dtor
	
	void login () ; // handles the login into the RVS cluster
	void logout () ; 
	void startVNCSession (std::string h, std::string m, std::string s) ; // starts a new session in the RVS cluster
	void executeRemoteCommand (std::string command) ; // Executes a command on the ssh server
	void upload (std::string fileLocation, std::string resultingDirectory) ; // uploads a file to the given account
	void printToStatusBar (std::string message) ; // prints a message to the status bar
	void connectToVNCSever (int node) ; // connects to the newly created VNC server at the RVS
	int returnVNCNode () ; // returns the node where the current VNC session is hosted
	
	inline void setUsername (std::string newUsername) {username = newUsername;}
	inline void setPassword (std::string newPassword) {password = newPassword;}
	inline void setVNCPassword (std::string newPassword) {vncPassword = newPassword;}
	
	inline std::string getUsername () {return username;}
		
	ssh_session sshSession ; // the ssh session which is created 
	ssh_channel channel ; // the ssh channel which is used for communication between the local machine and RVS
	
private:
	void setUpChannel () ; // sets up the channel (function called from login())
	std::string username ; 
	std::string password ; 
	std::string vncPassword ; 
} ; 

