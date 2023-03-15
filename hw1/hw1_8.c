#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int pfd[2]; // pipe file descriptor
    if (pipe(pfd) == -1){
        fprintf(stderr, "Pipe failed\n");
        exit(1);
    }

    pid_t pid1 = fork(); // create first child
    if (pid1 < 0){
        fprintf(stderr, "Fail to create first child process\n");
        exit(1);
    }
    else if (pid1 == 0){ // first child process -> input (write)
        printf("First child (ID: %d) of parent (ID: %d) will write (input of the pipe)\n", getpid(), getppid());
        close(pfd[0]); // close read
        dup2(pfd[1], STDOUT_FILENO); // redirect stdout -> write end of the pipe

        char *myargs[] = {"grep", "-o", "process", "./hw1_2.output", NULL};
        execv("/usr/bin/grep", myargs);
        exit(0);
    }
    else{
        pid_t pid2 = fork(); // create second child
        if (pid2 < 0){
            fprintf(stderr, "Fail to create second child process\n");
            exit(1);
        }
        else if (pid2 == 0){ // second child process -> output (read)
            printf("Second child (ID: %d) of parent (ID: %d) will read (output of the pipe)\n", getpid(), getppid());
            close(pfd[1]); // close write
            dup2(pfd[0],STDIN_FILENO); // redirect stdin -> read end of the pipe

            char *myargs[] = {"wc", "-l", NULL};
            execvp(myargs[0], myargs); // execute "wc -l" (word count program)
            exit(0);
        }
        else{ // parent process
            int status;
            close(pfd[0]);
            close(pfd[1]);
            waitpid(pid1, &status, 0);
            waitpid(pid2, &status, 0);
            //printf("Parent process (ID: %d)\n", getpid());
        }
    }
    return 0;
}