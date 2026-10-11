/*
DataTypes.h : is a glbal file that is used for the entierty of the program.

This contains primarily structs that are passed from one function to another or
some other component of MatrixSSH.

*/

#include <iostream>
#include <string>
#include <vector>

// Thest struct that is used within the program. 
struct test{

    // Test string
    std::string TestString;

    // Test int
    int TestInt;

    // Test char
    char TestChar;

};

// Connect Data : is used for containing info relating to making SSH
// Witch can range from username, IP/Host name, and some other data that
// will be needed.
struct SSH_ConnectionData{

    // Username data
    std::string SSH_UserName;

    // Password: its is raw so take caution.
    std::string SSH_Password;

    // The rest below can be user for other SSH info that a server may need to
    // deal with later on as this is to be determined. 

    // Port Number if needed
    int PortNumber;
    
};

/*
SSH Status: is a 2 in 1 data type that contains a string and intiger,

This can be expanded appon later if needed
*/
struct SSH_Status{

    // Status message string
    std::string SSH_Message;

    // Number code as int. This is mostly related to libSSH and other non
    // C++ stuff that is of the old C data tytes and what not.
    int SSH_CodeResult;

};

/*
MessageData : is used to transfer data from one entity to antother. 
*/
struct MessageData{

    // Data as a string
    std::string Data;

    // Entity name
    std::string EntityID;

};