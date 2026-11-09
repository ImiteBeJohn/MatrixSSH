/*
daemon_init: contains the soruce code that is uned in MatrixSSH.cpp
to start the code as a daemon process as needed.

*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#pragma once

int start_as_daemon_process(){

    // the pid of the process. 
    pid_t dem_pid;

    
}