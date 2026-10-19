/*
web_system : contains the specific code functions that will take HTTP request and 
handle the means of relaying that to the proper functions. 

Primarly all this dose is just take web data to C++ data so that this can inteface
with the SSH data stuff. 
*/

#include <iostream>
#include "httplib.h"
#include "../../DataTypes.h"
#pragma once

class WebEngine{

private:

    // Main server object
    httplib::Server EngineSvr;

    // Server port number, is usally 9090 but
    // to maintain flexability it the ens user can adjst it
    int SvrEnginePortNumber;

    // Ip numer to set the server as it stands
    int SvrIpAddr [4];

public:

    // Construtor and copy constructor
    WebEngine();
    
    WebEngine(const WebEngine &NewPtrID);

    /*
    Prime_server() : sets up the web server such as port, IP, and so on.

    This takes in Data messages as input and 
    */

};