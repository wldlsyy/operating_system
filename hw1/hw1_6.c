#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    pid_t rc = fork();
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0){ // child process
        printf("hello\n");
    }
    else{ // parent process
        int status;
        pid_t wpid = waitpid(rc, &status, 0);

        if (wpid == -1){ // 
            perror("wait failed\n");
        }
        if (WIFEXITED(status)) { // 자식 프로세스가 정상적으로 종료됨
            printf("Child process exited (Status: %d)\n", WEXITSTATUS(status));
        }

        printf("goodbye\n");
    }
}
