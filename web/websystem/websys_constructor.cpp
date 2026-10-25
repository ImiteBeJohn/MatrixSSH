/*
websys_constructor:

This contains the construtor and copy constructor as well.
*/

#include "web_system.h"
#pragma once

WebEngine::WebEngine(){

    // Dose nothing at the moment

}

// Copy constructor
WebEngine::WebEngine(const WebEngine &NewPtrID){

    // Use the port number
    this->SvrEnginePortNumber = NewPtrID.SvrEnginePortNumber;
    

}