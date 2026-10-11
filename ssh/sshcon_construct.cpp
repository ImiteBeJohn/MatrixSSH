/*
sshcon_construct : contains the constructor for this object. 

Currently all that it dose is the dynamic copy thing
to precent the shadow copy issue that I recall from some time ago.
*/

#include "ssh_connection.h"

ssh_session::ssh_session(){

    // So there is a copy pointer thing that is mean to prevent a class issue thing
    // I'mm still looking into it at the moment. 
}

// Copy constructor version
// Referecces this
// https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm
ssh_session::ssh_session(const ssh_session& PointerNew){

    // Use the session name as the "pointer"
    this->SessionName = PointerNew.SessionName;

}