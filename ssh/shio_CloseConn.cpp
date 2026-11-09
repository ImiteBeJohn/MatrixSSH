/* shio_CloseConn.cpp is used to contain the source code fo
closing active connection. This is essentally the program 
saying "I'm done with this connection"
*/

#include "shellio.h"
#pragma once

GeneralData ShellCon::CloseConn(){

    // Reurn data
    GeneralData ReturnData;

    // Close stuff based on the libssh data
    ssh_channel_close(RootChannel);
    ssh_channel_free(RootChannel);
    ssh_disconnect(RootSession);
    ssh_free(RootSession);
    
    // Set the reuturn
    ReturnData.MessageTitle = "Connection Closed";
    ReturnData.meSrc = "Any";
    ReturnData.DestSrc = SessionName;
    ReturnData.StringDataInfo = "Connection has been closed";
    ReturnData.IntDataInfo = 0;

    // Exit and return
    return ReturnData;
};