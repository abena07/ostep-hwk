// q5: Write a program that creates an array of integers called dataof size
// 100 using malloc; then, set data[100] to zero. What happens
// when you run this program? What happens when you run this
// program using valgrind? Is the program correct?

// there was a buffer overflow for the array because it ranges from 0-99 so modifiying
// the index at 100 won't work. there was also a memory leak because we did not free the memory

#include <stdlib.h>

int main(){

    int *data = malloc(100* sizeof(int));
    data[100] = 0;

    return 0;
}