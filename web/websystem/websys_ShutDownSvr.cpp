/*
ShutDownSvr(): contains the code do deactiave the server properly when needed
to. 
*/

#include "web_system.h"
#pragma once

WebStatus WebEngine::ShutdownSvr(){

    // Return for the data
    WebStatus ShutDownResult;

    // Stop the server
    EngineSvr.stop();

    // Return the result
    return ShutDownResult;
    
}