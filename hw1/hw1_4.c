#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int rc = fork(); // fork
    if (rc < 0){
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0){ // child process -> run program /bin/ls
        char *file = "/bin/ls";
        char *cmd = "ls";
        char *arg = "-l";
        char *envp[] = {NULL};
        char *myargs[] = {"/bin/ls", "-l", NULL};    
        
        // execl 계열은 argv 인수가 리스트로 나열됨
        execl(file, cmd, arg, NULL);
        execle(file, cmd, arg, NULL, envp);
        execlp(cmd, cmd, arg, NULL);

        // execv 계열은 argv 인수가 vector로 파라미터 하나를 받음
        execv(file, myargs);
        execvp(cmd, myargs);
        execvpe(file, myargs, env);
        fprintf(stderr, "exec failed\n");
    }
    else{ // parent process
        wait(NULL);
    }
}
