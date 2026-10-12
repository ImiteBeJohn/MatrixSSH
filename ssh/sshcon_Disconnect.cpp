/*
sshcon_Disconnect : is used to containt the code that will perform the disconnect 
for the ssh connection of libSSH.
*/

#include "ssh_connection.h"

SSH_Status ssh_dev::Disconnect(){

    // End the channel
    ssh_channel_close(DevChannelConn);

    // From the doc, but is needed
    ssh_channel_send_eof(this->DevChannelConn);

    // Disconnect
    ssh_disconnect(this->DevConnection);

    // Free the connection
    ssh_free(this->DevConnection);

};