/*
ssh_connection : is a class that is built for MatrixSSH specifically. 

ssh_connection is built around libssh libary that handles the SSH loweer level data
form one box to another (client to MatrixSSH).
*/

#include <iostream>
#include <string>
#include <libssh/libssh.h>
#include "../DataTypes.h"
#pragma once

class ssh_dev{

private:

    // Connection Name: the name of the object name itself that is 
    // used by the class to manage ssh objects.
    std::string SessionName;

    // Username of the SSH connection
    std::string SessionUserName;

    // HostName or IP of the connection
    std::string SessionHostName;

    // Port number of SSH
    int SessionPortNumber;

    // SSH connection status : from SSH itself
    std::string SessionStatusResults;

    // Class session status
    std::string SessionObjectStatus;

    // The SSH conection object
    ssh_session DevConnection;

    // SSH channel used for data communication
    ssh_channel DevChannelConn;

public:

    /* 
    Default constructor: Dose noting at the moment for now at lease. 
    */
    ssh_dev();

    /*
    Copy constructor : sense this uses libssh with is a more C based thing,
    it best assumed that it will be dealing with pointers. As such a copy 
    pointer is used to prevent issues
    Thanks CMPS 122. 
    */
    ssh_dev(const ssh_dev& PointerNew);

    /*
    Deconstructor witch dose nothing at the moment
    */
    ~ssh_dev();

    /*
    PrimeConnection() : set up an SSH connection with a username, password, 
    and so on before the connection is started. And a string name for
    naming the connection itself.

    This takes a connection data struct as input and returns noting.
    */
    void PrimeConnection(SSH_ConnectionData ConnectionInit, std::string NameID);

    /*
    ActivateConnection(): Will have make the connection to the host itself. 

    This takes notinh as a input and reutns a SSH_CodeReulst for program use
    */
    SSH_Status ActivateConnection();

    /*
    Dissconect() : ONLY TERMINATES the connection. Not the object itself. 
    
    This takes no input but reutns SSH status.
    */
    SSH_Status Disconnect();

    /*
    AlterConnection() : This changes existing connection when needed.
    This returns a SSH_Status and takes SSH_ConnectionData as input.
    */
    SSH_Status AlterConnection(SSH_ConnectionData ConnectionAlter);

    /*Test Connection : this is a simple "dose a means to communiate exist.
    
    retursn a SSH status*/
    SSH_Status TestConnection(MessageData TestCommand);

    /*Transerf: This is the communication data funcion that when called
    will push and get data from a connection
    
    This takes and returns MessageData types*/
    MessageData Tranfer(MessageData DataToSend);
    
};