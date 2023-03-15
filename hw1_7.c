#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0){ // child process
        printf("This is child process\n");
        sleep(1);
        close(STDOUT_FILENO);
        printf("Print after closing standard output\n");
    }
    else { // parent process
        wait(NULL);
        printf("This is parent process\n");
    }
}

