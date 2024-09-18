#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Generate a random float and convert it to a string
    float random_float = (float) rand() / RAND_MAX;
    char string[50];
    sprintf(string, "%f", random_float);

    // Generate two more random floats and convert them to strings
    float random_float2 = (float) rand() / RAND_MAX;
    char string2[50];
    sprintf(string2, "%f", random_float2);

    float random_float3 = (float) rand() / RAND_MAX;
    char string3[50];
    sprintf(string3, "%f", random_float3);

    // Print the resulting strings
    printf("String: %s\n", string);
    printf("String2: %s\n", string2);
    printf("String3: %s\n", string3);

    return 0;
}