/*
sshcon_PrimeConnection : contains the function for the PrimeConnection function.

PrimeConnection sets up variables (and in later cases test and verifys them)
for later use once the connection is activated. 
*/

#include "ssh_connection.h"

void ssh_dev::PrimeConnection(SSH_ConnectionData ConnectionInit, std::string NameID){

    // Set username
    this->SessionUserName = ConnectionInit.SSH_UserName;

    // Set password
    this->SessionStatusResults = ConnectionInit.SSH_Password;

    // Set port number
    this->SessionPortNumber = ConnectionInit.PortNumber;

    // Set the object status to "set" as a target is defined
    this->SessionObjectStatus = "set";

    // Set the name
    this->SessionName = NameID;

};