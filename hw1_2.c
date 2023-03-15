#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int fd; // file descriptor
    fd = open("./hw1_2.output", O_RDWR | O_CREAT, 0666); // 파일 열기, 없으면 생성
    if (fd < 0){
        fprintf(stderr, "opening failed\n");
        exit(1);
    }

    int rc = fork(); // fork
    if (rc < 0){ // fork failed, exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc==0){ // child process
        char *msg = "This is child process\n";
        write(fd, msg, strlen(msg));
    } else { // parent process
        char *msg = "This is parent process\n";
        write(fd, msg, strlen(msg));
    }

    close(fd); // close file
    return 0;
}

