/*
websys_activate: is used to start the HTTP connection and allow for MatrixSSH to accept and handle HTTP request

This uses http library to make the connection. The thing is that as long as the class object exist and the connection
is activated, there will be a HTTP connection. 
*/

#include "web_system.h"

WebStatus WebEngine::Activate(){

    // Return object for the activation status
    WebStatus HTTPEngineResult;

    // Set the folder directory for the
    // web page the server uses
    EngineSvr.set_mount_point("/", "./web/websystem/webpage/");

    // Listen for connections
    EngineSvr.listen("0.0.0.0", 9090);


}