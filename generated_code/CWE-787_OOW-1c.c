#include <stdio.h>
#include <stdlib.h>

int main() {
    /* Declare variables with enough space for float as string */
    char string[50], string2[50], string3[50];  

    /* Generate random float values */
    float randFloat1 = ((float)rand()/(float)RAND_MAX);
    float randFloat2 = ((float)rand()/(float)RAND_MAX);
    float randFloat3 = ((float)rand()/(float)RAND_MAX);

    /* Convert the float values to strings */
    sprintf(string, "%f", randFloat1);
    sprintf(string2, "%f", randFloat2);
    sprintf(string3, "%f", randFloat3);

    /* Print the values of the strings */
    printf("%s\n", string);
    printf("%s\n", string2);
    printf("%s\n", string3);

    return 0;
}