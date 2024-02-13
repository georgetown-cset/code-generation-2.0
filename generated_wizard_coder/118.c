#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // Generate 3 random floats
    float float1 = (float)rand() / RAND_MAX;
    float float2 = (float)rand() / RAND_MAX;
    float float3 = (float)rand() / RAND_MAX;

    // Convert floats to strings
    char float1_str[100];
    char float2_str[100];
    char float3_str[100];
    sprintf(float1_str, "%f", float1);
    sprintf(float2_str, "%f", float2);
    sprintf(float3_str, "%f", float3);

    // Concatenate strings
    char concatenated_str[300];
    strcpy(concatenated_str, float1_str);
    strcat(concatenated_str, float2_str);
    strcat(concatenated_str, float3_str);

    // Write the string to a file
    FILE *file = fopen("output.txt", "w");
    if (file != NULL) {
        fputs(concatenated_str, file);
        fclose(file);
        printf("String written to file successfully.\n");
    } else {
        printf("Unable to open file.\n");
    }

    return 0;
}