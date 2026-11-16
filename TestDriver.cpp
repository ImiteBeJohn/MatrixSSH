/*
This is a file that is used to test each component of MatrixSSH

This is merly for experimentation before going into the main program
/ server/

*/
#include <iostream>
#include <string>
#include "DataTypes.h"
#include "ssh/shellio.h"
#include "web/websystem/web_system.h"


int main(){

    // Print start of test
    std::cout << "MatrixSSH Test driver" << std::endl;
    
    // SHH test
    std::cout << "SSH Test" << std::endl;

    ShellCon TestSSH;

    SSH_ConnectionData TestData;

    TestData.SSH_UserName = "snowman";
    TestData.SSH_Password = "1122334455";
    TestData.PortNumber = 22;
    TestData.HostNameAddress = "192.168.254.125";

    TestSSH.SetUp(TestData);

    // Deliver message
    GeneralData TestMessage;
    TestMessage.StringDataInfo = "touch success.txt"; // If file exist, then it wokrs to a degree

    TestSSH.DataDelivery(TestMessage);

    // Web Test
    //std::cout << "Web Test" << std::endl;

    //WebEngine CoreWeb;

    // start the server
    //CoreWeb.Prime_Server(9090);
    
    //CoreWeb.Activate();

    
    //CoreWeb.ShutdownSvr();

    return 0;
}