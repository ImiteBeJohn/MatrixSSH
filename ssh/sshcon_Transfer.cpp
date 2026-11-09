/*
sshcon_Transfer is used for the transfer of data from the program to the connection
(or whater is running SSH that is) 

This uses the same MessageData in and out for communication. 
*/

#include "ssh_connection.h"

MessageData ssh_dev::Tranfer(GeneralData DataToSend){

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

    // If it did not work, then return that the channel open
    // failed
    if(ChannelNumberResult != SSH_OK){

        // Return that the SSH channel did not open
        TransferResult.LocalCommand = "SshChannelError";
        TransferResult.FluffData = "The channel failed to open: SSH_OK was false";

        // Place entity name
        TransferResult.EntityID = this -> SessionName;

        // Return 
        return TransferResult;
    }

    // OTherwise, make the delivery

    // From what I looked into, this is the write function
    // that "writes" into the connection

    // needed numbers

    // collums needed, use the string length for the number
    int NumColls = DataToSend.StringDataInfo.length();

    // rows needed, for this sake we use 1 for now
    int NumRows = 1;

    // The first is to request the pty and the shell
    if(ssh_channel_request_pty(DevChannelConn) != SSH_OK || 
    ssh_channel_request_shell(DevChannelConn) != SSH_OK){

        // Return an error. 
        TransferResult.Data = "pty_shell_error";
        TransferResult.EntityID = this -> SessionName;
        TransferResult.FluffData = "There was an error with the request: " + static_cast<std::string>(ssh_get_error(DevChannelConn));

        // Return and exit
        return TransferResult;
    }

    // Once we make it to this point, then we first write 
    // (send data to the connection)
    // then read from the connection
    // (get data to the connection)
    // to witch its assumed the command will reurn some result
    // and return them

    // Send if not return error if failed. 
    if(ssh_channel_write(DevChannelConn, DataToSend.StringDataInfo.c_str(), NumColls)
    != SSH_OK){

        // Return the error as allways 
        TransferResult.Data = "ssh_write_faut";
        TransferResult.EntityID = this -> SessionName;
        TransferResult.FluffData = "Error wrtiting to host: " + static_cast<std::string>(ssh_get_error(DevConnection));

        // Exit and return
        return TransferResult;
    }

    // Buffer from tutorial
    char tbuff[256];

    // Otherwise read from the connection, then we close 
    ssh_channel_read(DevChannelConn, tbuff, sizeof(tbuff), 0);

    // Convert the tbuff to the string for return
    TransferResult.FluffData = static_cast<std::string>(tbuff);

    // Report success
    TransferResult.Data = "CommSuccess";
    TransferResult.EntityID = this -> SessionName;

    // Close the connection
    ssh_channel_send_eof(DevChannelConn);
    ssh_channel_close(DevChannelConn);
    ssh_channel_free(DevChannelConn);

    // Return Transfer result
    return TransferResult;

};