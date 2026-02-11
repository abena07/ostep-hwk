// qn: Write another program using fork(). The child process should
// print “hello”; the parent process should print “goodbye”. You should
// try to ensure that the child process always prints first; can you do
// this without calling wait() in the parent?

#include <stdio.h>
#include <unistd.h>

int main(){

    int rc = fork();

    if (rc < 0){
        printf("an error happened\n");
    }else if(rc == 0){
        printf("hello\n");
    }else{
        sleep(3);
        printf("goodbye\n");
        
    }
}