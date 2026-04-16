// q7: Now pass a funny value to free (e.g., a pointer in the middle of the
// array you allocated above). What happens? Do you need tools to
// find this type of problem?

// ans: the free was done in a bad "way"

#include <stdlib.h>
#include <stdio.h>

int main(){
    int *data = malloc(100 * sizeof(int));
    free(data + 50);
    printf("value : %d\n", data[1]);


    return 0;
}