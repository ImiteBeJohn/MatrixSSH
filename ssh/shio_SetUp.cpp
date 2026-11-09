/*
shio_setUp.cpp is used to contain the soruce code for the SSH class
*/

#include "shellio.h"
#pragma once

MessageData ShellCon::SetUp(SSH_ConnectionData SetUp){

    
    // Return type
    MessageData result;

    // Map from SetUp to the class values. 
    SessionName = SetUp.AssingedConnectionName;

    // Map user longin account
    LoginID = SetUp.SSH_UserName;

    // Map the account password
    ConnectionPassword = SetUp.SSH_Password;

    // If the assinged port is null or not 22 then set it
    // Otherwise set it to 22
    if(SetUp.PortNumber == 0 || SetUp.PortNumber != 22){

        // Set port
        ConnectionPortNumber = SetUp.PortNumber;
    }else{

        // Make it 22 as default
        ConnectionPortNumber = 22;
    }

    // Set the host conection info
    HostAddressInfo = SetUp.HostNameAddress;

    // Define the path to the key
    SSHKeyPath = SetUp.KeyPathDir;


    // Return results
    result.Data = "SSH connection setup successful";
    result.EntityID = SessionName;
    result.LocalCommand = "SetUp";
    result.FluffData = "Additional info if needed";

    // Return
    return result;
};