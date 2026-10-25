/*
websys_Prime_Server: contains the source code for the Prime_Server() class functions.

The purpose of this code is to allow for the web system to be configured so that when activated will configure the listening IP address to follow and
what port it's to use

Normally MatrixSSH uses port 9090 but in some cases a user can configure custom ports
*/

#include "web_system.h"
#pragma once

WebStatus WebEngine::Prime_Server(GeneralData ConfigData){

    // Return for the data
    WebStatus PrimeResult;

    // First map the IP address
    SvrIpAddr[0] = ConfigData.IntMicroArr[0];
    SvrIpAddr[1] = ConfigData.IntMicroArr[1];
    SvrIpAddr[2] = ConfigData.IntMicroArr[2];
    SvrIpAddr[3] = ConfigData.IntMicroArr[3];

    // Then assing port number
    SvrEnginePortNumber = ConfigData.IntDataInfo;

    // Return the status
    PrimeResult.ErrorStringCode = "Prme Server: Ip address set";

    // Some string stuff, for the extra message
    std::string MakeMessage = "The server is configured for the IP address ";
    MakeMessage + std::to_string(ConfigData.IntMicroArr[0]);
    MakeMessage + ".";
    MakeMessage + std::to_string(ConfigData.IntMicroArr[1]);
    MakeMessage + ".";
    MakeMessage + std::to_string(ConfigData.IntMicroArr[2]);
    MakeMessage + ".";
    MakeMessage + std::to_string(ConfigData.IntMicroArr[3]);
    MakeMessage + " and the port number ";
    MakeMessage + std::to_string(ConfigData.IntDataInfo);

    // TO the struct
    PrimeResult.ExtraMsg = MakeMessage;

    // Return the result
    return PrimeResult;
    
}