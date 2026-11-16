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

    // If it failed to deamonize, then retunr a failure
    if((dem_pid = fork()) < 0){

        return -1;
    }
    else if(dem_pid != 0){
        exit(0);
    }

    // Then we set the file mode mask to 0
    umask(0);

    // Change directory to root
    chdir("/");

    // Point output to /dev/null
    int fd0 = open("/dev/null", O_RDWR);
    int fd1 = dup(0);
    int fd2 = dup(0);

    // Write the pid to a file for later use
    FILE *pid_file = fopen("/var/run/matrixssh.pid", "w");
    if (pid_file) {
        fprintf(pid_file, "%d", getpid());
        fclose(pid_file);
    }

    return 0;
}