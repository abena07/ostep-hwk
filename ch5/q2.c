// qn: Write a program that opens a file (with the open() system call)
// and then calls fork()to create a new process. Can both the child
// and parent access the file descriptor returned by open()? What
// happens when they are writing to the file concurrently, i.e., at the
// same time?
//
// ans: yes both of them can access the fd returned by open() after fork()
// when they are writing to the file concurrently they share the same file offset
// this can result in overlapping or a race condition.

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int fd = open("temp.txt", O_CREAT | O_WRONLY , 0644);

    if (fd == -1) {
        printf("an error happend\n");
        exit(1);
    }

    int rc = fork();

    if (rc < 0){
        printf("fork failed\n");
    }else if(rc == 0){

        const char *buffer = "i am a child\n";
        write(fd, buffer, strlen(buffer));

        printf("wrote to child %d\n", fd);
        close(fd);
    }else{

        const char *buffer ="i am a parent\n";
        write(fd, buffer, strlen(buffer));
        
        printf("wrote to parent %d\n", fd);
        close(fd);
    }
    return 0;
}