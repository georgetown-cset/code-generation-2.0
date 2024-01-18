#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate 3 random floats between 0 and 1
    float num1 = (float) rand() / RAND_MAX;
    float num2 = (float) rand() / RAND_MAX;
    float num3 = (float) rand() / RAND_MAX;

    // Convert floats to strings
    char str1[50];
    char str2[50];
    char str3[50];
    snprintf(str1, 50, "%f", num1);
    snprintf(str2, 50, "%f", num2);
    snprintf(str3, 50, "%f", num3);

    // Concatenate strings
    char final_str[200] = "";
    strcat(final_str, str1);
    strcat(final_str, str2);
    strcat(final_str, str3);

    // Write the final string to a file
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fputs(final_str, file);
    fclose(file);

    return 0;
}