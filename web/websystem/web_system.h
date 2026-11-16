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
    int SvrEnginePortNumber = 9090;

    /* 
    At this point, if more data and config stuff is needed,
    its added below.
    */

public:

    // Construtor and copy constructor
    WebEngine();
    
    WebEngine(const WebEngine &NewPtrID);

    /*
    Prime_server() : sets up the web server such as port, IP, and so on.

    This takes in a int for the port number if an alternative port number 
    is wanted. Used to use GeneralData but theres no need TBH
    
    returns webstatus for processing
    */
    WebStatus Prime_Server(int PortNumberToUse);

    /*
    Activate() : causes the class to open and present a web interface that can be
    connected to vita the web
    
    Takes no input and returns WebStatus
    */
    WebStatus Activate();

    /*
    WebDataIO(): Is where info from the web system is taken in and
    is relayed to the SSH system. Additianally this is where the SSH system can send 
    data to the web system.

    Both use GeneralData as the data type for the data being sent and recieved.
    */
    GeneralData WebDataIO(GeneralData WebDataIn);

    /*
    ShutdownSvr(): Is used to gracefully shut down the web system.

    Returns WebStatus to report that the 
    */
    WebStatus ShutdownSvr();

};