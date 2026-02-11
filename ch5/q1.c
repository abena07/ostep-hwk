// 1. Write a program that calls fork(). Before calling fork(), have the
// main process access a variable (e.g., x) and set its value to some-
// thing (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change
// the value of x?
// ans: the value of the variable in the child process is 200 
// the variables create different copies of x both in the parent and child which are independent

#include <stdio.h>
#include <unistd.h>

int main() {
 
    printf("hello world\n");
    int x = 100;
    int rc = fork();

    if (rc < 0){
        printf("fork failed\n");
    }else if (rc == 0){
        x = 200;
        printf("child %d\n", x);
    } else{
        x = 300;
        printf("parent %d\n", x);
    }
    printf("x after mutation %d\n", x);
    return 0;
}