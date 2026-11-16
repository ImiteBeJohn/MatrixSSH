#include <iostream>
#include "ssh/shellio.h"
#include "web/websystem/web_system.h"
#include "storagebase/connect/hoststorage.h"
#include "DataTypes.h"
#include "functions/daeom_init.h"



int main(int argc, char* argv[]){

  // Fork as a daemon
  if (start_as_daemon_process() == -1) {

    // Error out
    std::cerr << "MatrixSSH error: Failed to fork" << std::endl;

    return 1;
  }

  // At this point, the matrix system should then read and process 
  // Config files, stored in places like /etc/matrixssh/config.conf
  // 
  // After that it loads its connection database for stored SSH connections
  // and 

  // Collection of SSH connections, 10 at the moment
  ShellCon Con1, Con2, Con3, Con4, Con5, Con6, Con7, Con8, Con9, Con10;

  // Then start the web system
  WebEngine CoreWeb;

  // start the server
  CoreWeb.Prime_Server(9090);
  CoreWeb.Activate();

  // Operation loop.
  bool ExitServerProcess = false;
  
  // Loop
  while(!ExitServerProcess){

    

  }
}
