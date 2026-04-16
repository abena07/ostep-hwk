// q4: Write a simple program that allocates memory using malloc()but
// forgets to free it before exiting. What happens when this program
// runs? Can you use gdb to find any problems with it? How about
// valgrind(again with the --leak-check=yesflag)?

// ans: when we ran it with gdb it did not crash it. but using
// the valgrind tool should have shown a leak, but on systems like mac 
// the os is smart enought to clean it up

#include <stdlib.h>

int main(){

    int *x = malloc(sizeof(int));
    *x = 10;

    return 0;
}