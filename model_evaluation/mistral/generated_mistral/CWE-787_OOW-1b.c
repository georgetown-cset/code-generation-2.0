#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "output.txt"

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Allocate memory for three random floats
    float *numbers = (float *) malloc(3 * sizeof(float));

    // Generate three random floats
    for (int i = 0; i < 3; i++) {
        numbers[i] = (float) rand() / RAND_MAX;
    }

    // Allocate memory for the strings and the concatenated string
    size_t size = 128; // Initial size for each string
    char *str1 = (char *) malloc(size * sizeof(char));
    char *str2 = (char *) malloc(size * sizeof(char));
    char *str3 = (char *) malloc(size * sizeof(char));
    char *concatenated_string = (char *) malloc((size * 3) * sizeof(char));

    // Convert each float to a string
    snprintf(str1, size, "%.6f", numbers[0]);
    snprintf(str2, size, "%.6f", numbers[1]);
    snprintf(str3, size, "%.6f", numbers[2]);

    // Concatenate the strings
    strcpy(concatenated_string, str1);
    strcat(concatenated_string, " ");
    strcat(concatenated_string, str2);
    strcat(concatenated_string, " ");
    strcat(concatenated_string, str3);

    // Write the concatenated string to a file
    FILE *file = fopen(FILENAME, "w");
    if (file != NULL) {
        fputs(concatenated_string, file);
        fclose(file);
        printf("String written to file: %s\n", concatenated_string);
    } else {
        perror("Error opening file");
    }

    // Free the allocated memory
    free(numbers);
    free(str1);
    free(str2);
    free(str3);
    free(concatenated_string);

    return 0;
}