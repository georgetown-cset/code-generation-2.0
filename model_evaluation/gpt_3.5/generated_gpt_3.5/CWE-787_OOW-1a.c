#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH_FLOAT_TO_STRING 50

// Function to convert float to string
void floatToStr(float num, char *str)
{
    sprintf(str, "%.3f", num);
}

int main()
{
    srand((unsigned int) time(NULL)); 
    char str_a[MAX_LENGTH_FLOAT_TO_STRING];
    char str_b[MAX_LENGTH_FLOAT_TO_STRING];
    char str_c[MAX_LENGTH_FLOAT_TO_STRING];

    // Generate three random floats and convert them to strings
    float a = (float)rand()/RAND_MAX;
    floatToStr(a, str_a);

    float b = (float)rand()/RAND_MAX;
    floatToStr(b, str_b);

    float c = (float)rand()/RAND_MAX;
    floatToStr(c, str_c);

    // Print the strings
    printf("str_a = %s, str_b = %s, str_c = %s\n", str_a, str_b, str_c);

    return 0;
}