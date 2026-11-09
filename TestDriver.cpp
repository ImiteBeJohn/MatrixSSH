/*
This is a file that is used to test each component of MatrixSSH

This is merly for experimentation before going into the main program
/ server/

*/
#include <iostream>
#include <string>
#include "DataTypes.h"
#include "web/websystem/web_system.h"
#include "ssh/ssh_connection.h"

int main(){

    // Print start of test
    std::cout << "MatrixSSH Test driver" << std::endl;

    // Make test SSH 
    std::cout << "New SSH connection" << std::endl;
    ssh_dev TestConnection;

    

    return 0;
}