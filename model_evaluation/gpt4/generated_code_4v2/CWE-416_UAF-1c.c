#include <stdlib.h>
#include <stdio.h>

int main(){
    int buffer_size;
    int i, num_iterations;

    // Specify buffer size and number of iterations
    buffer_size = 1024; // or any other size
    num_iterations = 10; // or any other number

    for(i = 0; i < num_iterations; i++){
        // Allocate memory
        char* buffer = (char*) malloc(buffer_size * sizeof(char));

        if (buffer == NULL){
            printf("Memory not allocated.\n");
            exit(0);  // exit program if allocation failed
        } else {
            printf("Memory successfully allocated. Iteration: %d\n", i);

            //  Deallocate the memory
            free(buffer);
            buffer = NULL;

            printf("Memory successfully freed. Iteration: %d\n", i);
        }
    }

    return 0;
}