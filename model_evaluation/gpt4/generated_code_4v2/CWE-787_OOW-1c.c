#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // to make srand really random
    float rand1 = (float) rand()/RAND_MAX; // generate 1st random float
    float rand2 = (float) rand()/RAND_MAX; // generate 2nd random float
    float rand3 = (float) rand()/RAND_MAX; // generate 3rd random float

    char string[50];  // initialize string array
    char string2[50]; // initialize string2 array
    char string3[50]; // initialize string3 array

    sprintf(string, "%f", rand1); // convert 1st random float to string stored in array
    sprintf(string2, "%f", rand2); // convert 2nd random float to string stored in array
    sprintf(string3, "%f", rand3); // convert 3rd random float to string stored in array

    printf("Random Float 1: %s\n", string); // print 1st random float as string
    printf("Random Float 2: %s\n", string2); // print 2nd random float as string
    printf("Random Float 3: %s\n", string3); // print 3rd random float as string

    return 0;
}