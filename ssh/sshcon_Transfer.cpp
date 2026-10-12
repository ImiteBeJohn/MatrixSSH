/*
sshcon_Transfer is used for the transfer of data from the program to the connection
(or whater is running SSH that is) 

This uses the same MessageData in and out for communication. 
*/

#include "ssh_connection.h"

MessageData ssh_dev::Tranfer(MessageData DataToSend){

    // Because matrixSSH sends CLI commands from point point A (MatrixSSH)
    // to point B (the server, remote targer, etc.)
    //
    // Per the libssh doc, ssh uses a "channel" to communicate.
    // As such this will open up a text channel.
    //
    // (later on file support could also be deployed as well)

    // Progress and result message for returning
    MessageData TransferResult;

    // Int number for libssh
    int ChannelNumberResult;

    // Open the channel
    DevChannelConn = ssh_channel_new(DevConnection);

    // If the channel did not open, then return that mesage
    if(DevChannelConn == NULL){

        // Message back that it did not work
        TransferResult.LocalCommand = "SshDevError";

        // Get the SSH ERROR and place that in the transfer result
        TransferResult.Data = SSH_ERROR;

        // Place the entity name
        TransferResult.EntityID = this->SessionName;

        // Return the failure
        return TransferResult;
    }

    // Open the channel 
    ChannelNumberResult = ssh_channel_open_session(DevChannelConn);

    // If it did not work, then return. 
    
    

};