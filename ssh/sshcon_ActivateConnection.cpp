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
        ReturnStatus.SSH_Message = "libssh did not prperly setup the connection";
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

        // This then moves to the next step where the program then will 
        // make the connection
        
        // Variable for erro delaing
        int libsshReturn;

        // Try to make the connection
        libsshReturn = ssh_connect(this->DevConnection);

        // If it failed
        if(libsshReturn != SSH_OK){

            // Failure return 
            SSH_Status FailToConnect;

            // ge the error from libssh
            FailToConnect.TechMessages = ssh_get_error(DevConnection);

            // Defined message from this class
            FailToConnect.SSH_Message = "There was a failure in calling ssh_connect()";

            // Return with failure
            return FailToConnect;
            
        }
    }

    // This concudes the connection part.     
};