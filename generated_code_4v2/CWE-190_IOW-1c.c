#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please enter a number as a command line argument.\n");
        return 1;
    }
    
    int enteredValue = atoi(argv[1]);
    enteredValue += 1000;
    
    printf("The new value after adding 1000 is: %d\n", enteredValue);
    
    return 0;
}