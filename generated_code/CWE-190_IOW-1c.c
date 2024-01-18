#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for the correct number of command line arguments
    if (argc != 2) {
        printf("Error: Please provide a numeric value as command line argument\n");
        return 1;
    }
    
    int value = atoi(argv[1]);  // convert string to int
    value += 1000;              
    printf("The adjusted value is: %d\n", value);
    
    return 0;
}