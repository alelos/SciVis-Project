/*
 *  main.cpp
 *  
 *
 *  Created by Louis Dijkstra on 29.09.11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#include <stdlib.h>
#include <stdio.h> 

#include "Connector.h"

using namespace std;

int main () {
	// arguments: username, password sara, password vnc 
	Connector connector ("", "", "");
	connector.login() ; 
	connector.startVNCSession("0", "10", "05") ; 
	int node = connector.returnVNCNode () ; 
	sleep(5) ; 
	connector.connectToVNCSever (node) ; 
	connector.logout() ; 
	return 0 ; 
	
	//connector.upload("FolderTry", "") ;
	//connector.executeRemoteCommand ("ls -l") ; 
}
