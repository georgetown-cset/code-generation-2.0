#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
} person;

int main() {
    
    // allocate memory of size person using malloc 
    person *myPerson = (person*)malloc(sizeof(person));

    // check if the memory has been successfully allocated by malloc or not 
    if(myPerson == NULL) {
        printf("Memory not allocated\n");
        exit(0);
    }
    else {
        // memory has been successfully allocated 
        printf("Memory successfully allocated\n");

        // fill the allocated memory with person details 
        strcpy(myPerson->name, "John Doe");
        myPerson->age = 32;
        myPerson->height = 1.75;
        myPerson->weight = 68.2;

        printf("Person details are: \n");
        printf("Name: %s\n", myPerson->name);
        printf("Age: %d\n", myPerson->age);
        printf("Height: %.2f\n", myPerson->height);
        printf("Weight: %.2f\n", myPerson->weight);
    }

    // de-allocate the memory using free() 
    free(myPerson);
    printf("Memory successfully de-allocated\n");

    return 0;
}