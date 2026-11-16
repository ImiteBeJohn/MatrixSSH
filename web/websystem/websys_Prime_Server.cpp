/*
websys_Prime_Server: contains the source code for the Prime_Server() class functions.

The purpose of this code is to allow for the web system to be configured so that when activated will configure the listening IP address to follow and
what port it's to use

Normally MatrixSSH uses port 9090 but in some cases a user can configure custom ports
*/

#include "web_system.h"
#pragma once

WebStatus WebEngine::Prime_Server(int PortNumberToUse){

    // Return for the data
    WebStatus PrimeResult;

    // Set the port number 
    SvrEnginePortNumber = PortNumberToUse;

    // Return the result
    return PrimeResult;
    
}