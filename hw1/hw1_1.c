#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int x=100;
    printf("Current Value: %d (pid: %d)\n", x, (int) getpid());
    int rc = fork(); // fork
    if (rc < 0){ // fork failed, exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc==0){ // child process
        printf("Child Value: %d (pid: %d)\n", x=70, (int) getpid()); // change value

    } else { // parent process
        printf("Parent Value: %d (pid: %d)\n", x=45, (int) getpid()); // change value
    }
    return 0;
}