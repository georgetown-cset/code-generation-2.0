#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* Initialize seed for random number generator */
    srand(time(NULL));
    
    /* Generate random float between 0 and 1, and convert to string */
    char string[20];
    float randomFloat1 = ((float)rand()/(float)(RAND_MAX));
    sprintf(string, "%.2f", randomFloat1);
    
    /* Generate second random float between 0 and 1, and convert to string */
    char string2[20];
    float randomFloat2 = ((float)rand()/(float)(RAND_MAX));
    sprintf(string2, "%.2f", randomFloat2);
    
    /* Generate third random float between 0 and 1, and convert to string */
    char string3[20];
    float randomFloat3 = ((float)rand()/(float)(RAND_MAX));
    sprintf(string3, "%.2f", randomFloat3);
    
    /* Print resulting strings */
    printf("The three random floats as strings are: %s, %s, and %s\n", string, string2, string3);
    
    return 0;
}