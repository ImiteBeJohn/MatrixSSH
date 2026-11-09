/*
shellio.h: is a new ssh class that is a even more simplified SSH system.
It contains the following
* Construtors
* SetupConnection(SSH_ConnectionData)
* Deliver(GeneralData)
* StopConnection()
* UpdateConnection()
* Status()
* EntityInfo() <- is more related to the class than SSH itself

This replaces ssh_connection.h and ssh_dev with ShellCon
*/

#include <iostream>
#include <string>
#include <libssh/libssh.h>
#include "../DataTypes.h"
#pragma once

class ShellCon{

    private:

    // Class specific parts

    // SessionName is a generi name that is used for program reference
    // Ie "web server" "database" and so on
    std::string SessionName;

    // Login name that is used
    std::string LoginID;

    // Password
    std::string ConnectionPassword;

    // Host name or IP address 
    std::string HostAddressInfo;

    // Port number: generally 22 but varies
    int ConnectionPortNumber;

    // Status contains the current state of the class object. Has 3 states
    //
    // idle   : set but not in use
    // fresh  : exist but no host name or anything is defined
    // active : is currently exchanging data from one system to this program
    std::string ConnectionStatus;

    // Path to the SSH key where stored
    std::string SSHKeyPath;

    /*
    Is is based on the overall typs that an libssh connection will used 
    during its connection process overall. 

    Now relatvely there are two components to libssh
    channel and session
    session is a connection that is established with ssh
    a channel is a means of communicate. This can be X-display, files, or text aka
    bash or command shell.
    */
    ssh_session RootSession;
    ssh_channel RootChannel;
    ssh_key ConnectionKey = nullptr;

    public:

    // Construtor: dose nothing at the momnent
    ShellCon();

    // Decon: just close everything even iff there is no connection
    ~ShellCon();

    /*SetUp() is used to initialize the SSH object. This is used to 
    configure the object to take and accept SSH connections
    
    This takes in a SSH_ConnectionData struct for the SSH connection and then
    returns a message data for the result*/
    MessageData SetUp(SSH_ConnectionData SetUp);

    /*CloseConn() tells the object that I'm no longer using the connection
    This takes no parmamiters and reutns GeneralData as a status code*/
    GeneralData CloseConn();

    /*DataDelivery() is where data comes in and out of the program
    
    This take in a general data struct for input and reutns one as well
    */
    GeneralData DataDelivery(GeneralData DataIn);
    

};