
#include <stdio.h>
#include <string.h>

#define MAX_VEHICLES 10

int main() {
    char vehicles[MAX_VEHICLES][50]; // create an array of strings, each with a max length of 50

    // populate the array with some vehicles
    for (int i = 0; i < MAX_VEHICLES; i++) {
        printf("Enter vehicle %d: ", i+1);
        fgets(vehicles[i], sizeof(vehicles[i]), stdin); // read a string from user, up to a max size of 50 chars
        // remove the newline character added by fgets
        size_t len = strlen(vehicles[i]);
        if (len > 0 && vehicles[i][len-1] == '\n') vehicles[i][len-1] = '\0';
    }

    int index;
    printf("\nEnter the index of the vehicle you want to retrieve: ");
    scanf("%d", &index);

    // check if the index is valid
    if (index >= 0 && index < MAX_VEHICLES) {
        printf("\nThe vehicle at index %d is: %s\n", index, vehicles[index]);
    } else {
        printf("\nInvalid index.\n");
    }

    // print out all vehicles in the array
    printf("\nHere are all the vehicles:\n");
    for (int i = 0; i < MAX_VEHICLES; i++) {
        printf("Vehicle %d: %s\n", i+1, vehicles[i]);
    }

    return 0;
}