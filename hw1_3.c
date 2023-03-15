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
        printf("hello\n");
    }
    else{ // parent process
        sleep(1); // delay parent process
        printf("goodbye\n");
    }
}
