/* Constructor and Destructor for SSH connection */

#include "shellio.h"

ShellCon::ShellCon() {

    // Do nothing at the moment
}

ShellCon::~ShellCon() {

    // Use the exising CloseConn() function to close the connection and free up memory
    CloseConn();
}