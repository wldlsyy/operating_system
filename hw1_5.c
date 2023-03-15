#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0){ // child process
        //int wc = wait(NULL);     
        printf("hello (child pid: %d)\n", (int) getpid());
        //printf("Return value of wait(): %d\n", wc);
    }
    else{ // parent process
        int wc = wait(NULL);
        printf("goodbye (parent pid: %d)\n", (int) getpid());
        printf("Return value of wait(): %d\n", wc);
    }
}
