// Create a program that allocates an array of integers (as above), frees
// them, and then tries to print the value of one of the elements of
// the array. Does the program run? What happens when you use
// valgrind on it?

// the program aborts with an error when we use address sanitizer(sub for valgrind)
// without address sanitizer it runs but it's not correct in essence

#include <stdlib.h>
#include <stdio.h>

int main(){

    int *data = malloc(100 * sizeof(int));
    printf("value : %d\n", data[1]);

    free(data);


    return 0;
}