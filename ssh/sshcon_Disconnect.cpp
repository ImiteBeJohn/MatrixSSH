/*
sshcon_Disconnect : is used to containt the code that will perform the disconnect 
for the ssh connection of libSSH.
*/

#include "ssh_connection.h"

SSH_Status ssh_dev::Disconnect(){

    // Disconnect
    ssh_disconnect(this->DevConnection);

    // Free the connection
    ssh_free(this->DevConnection);

};