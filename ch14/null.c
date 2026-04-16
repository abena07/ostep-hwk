// q1.First, write a simple program called null.c that creates a pointer
// to an integer, sets it to NULL, and then tries to dereference it. Com-
// pile this into an executable called null. What happens when you
// run this program?
//
// ans: when i run this program it crashes with a segmentation fault

// q2. Next, compile this program with symbol information included (with
// the -g flag). Doing so let’s put more information into the exe-
// cutable, enabling the debugger to access more useful information
// about variable names and the like. Run the program under the de-
// bugger by typing gdb nulland then, once gdbis running, typing
// run. What does gdb show you?

// ans:  after adding the g flag we saw a more verbose error message and an indicator on 
// what line caused the error

// Finally, use the valgrindtool on this program. We’ll use the memcheck
// tool that is a part of valgrind to analyze what happens. Run
// this by typing in the following: valgrind --leak-check=yes
// null. What happens when you run this? Can you interpret the
// output from the tool?

// 


#include <stdio.h>

int main(){
    int *ptr = NULL;
    printf("value : %d\n", *ptr);
}