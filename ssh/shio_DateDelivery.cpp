/* shio_DateDelivery.cpp is used to contain the source code for delivering 
Conetent from Matrix SSH to the desiered target
*/

#include "shellio.h"
#pragma once

GeneralData ShellCon::DataDelivery(GeneralData DataIn){

    // return obj
    GeneralData RetrunData;

    // This is the general libssh stuff here

    // Firs the session
    if(ssh_channel_new(RootSession) != SSH_OK){

        // Return that the channel creation failed
        RetrunData.MessageTitle = "Error";
        RetrunData.StringDataInfo = "Channel creation failed";
        RetrunData.IntDataInfo = ssh_get_error_code(RootSession);
        RetrunData.DestSrc = SessionName;
        return RetrunData;
    }

    // Then the channel
    if(ssh_channel_open_session(RootChannel) != SSH_OK){

        // Return that the channel creation failed
        RetrunData.MessageTitle = "Error";
        RetrunData.StringDataInfo = "Channel opening failed";
        RetrunData.IntDataInfo = ssh_get_error_code(RootSession);
        RetrunData.DestSrc = SessionName;
        return RetrunData;
    }

    // Set the options for the channel and session
    ssh_options_set(RootSession, SSH_OPTIONS_USER, LoginID.c_str());
    ssh_options_set(RootSession, SSH_OPTIONS_HOST, HostAddressInfo.c_str());
    ssh_options_set(RootSession, SSH_OPTIONS_PORT, &ConnectionPortNumber);

    // Connect to the host
    
    // Number for the connecton
    int ConnectionResult = ssh_connect(RootSession);

    // If the connction failed, then return the error
    if(ConnectionResult != SSH_OK){
        
        // Return that the channel creation failed
        RetrunData.MessageTitle = "Error";
        RetrunData.StringDataInfo = "Connection failed";
        RetrunData.IntDataInfo = ssh_get_error_code(RootSession);
        RetrunData.DestSrc = SessionName;
        return RetrunData;
    }

    // Deliver the command
    if(ssh_channel_request_exec(RootChannel, DataIn.StringDataInfo.c_str()) != SSH_OK){
        
        // Return that the channel creation failed
        RetrunData.MessageTitle = "Error";
        RetrunData.StringDataInfo = "Command execution failed";
        RetrunData.IntDataInfo = ssh_get_error_code(RootSession);
        RetrunData.DestSrc = SessionName;
        return RetrunData;
    }

    // If everything is successful, then we get what the server gain from us
    char buffer[8192];
    int numberOfBytes = ssh_channel_read(RootChannel, buffer, sizeof(buffer), 0);

    // Loop to read all and store to for return data
    while(numberOfBytes > 0){

        // Store the data to the return data
        RetrunData.StringDataInfo.append(buffer, numberOfBytes);

        // Read again
        numberOfBytes = ssh_channel_read(RootChannel, buffer, sizeof(buffer), 0);
    }

    // Call the close function
    ssh_channel_send_eof(RootChannel);
    ssh_channel_close(RootChannel);
    ssh_channel_free(RootChannel);
    ssh_disconnect(RootSession);
    ssh_free(RootSession);

    return RetrunData;
}