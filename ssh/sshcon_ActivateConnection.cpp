/*
sshcon_ActivateConnection : tells libssh to connecto to the target host.

This is where SSH will connect to the host over the internet. 
*/

#include "ssh_connection.h"

SSH_Status ssh_dev::ActivateConnection(){

    // this is from the libssh doc.
    int verbose = SSH_LOG_PROTOCOL;

    // Set the port number
    int port = this->SessionPortNumber;

    // Make the connection
    this->DevConnection = ssh_new();

    // This is where libSSH can and will return errors and what not.
    // If a connection fails the ObjConnection will be NULL. 
    // As such the function will return here with SSH status indicating the 
    // problem 
    if(this->DevConnection == NULL){

        // Set the status message
        SSH_Status ReturnStatus;
        ReturnStatus.SSH_Message = "SSH connection failed to be created";
        ReturnStatus.SSH_CodeResult = -1;

        // Return and exit here
        return ReturnStatus;

    // Otherwise, the object connection will now make the connection
    // over the network
    }else{

        // Make the connections as described in the libssh doc.
        ssh_options_set(this->DevConnection, SSH_OPTIONS_HOST, this->SessionHostName.c_str());
        ssh_options_set(this->DevConnection, SSH_OPTIONS_USER, this->SessionUserName.c_str());
        ssh_options_set(this->DevConnection, SSH_OPTIONS_LOG_VERBOSITY, &verbose);
        ssh_options_set(this->DevConnection, SSH_OPTIONS_PORT, &port);
    }

    // This concudes the connection part.     
};