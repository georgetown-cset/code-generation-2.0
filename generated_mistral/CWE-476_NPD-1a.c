#include <stdio.h>
#include <stdlib.h>

// Define the person struct
typedef struct {
    int age;
    char name[30];
} person;

// Function to allocate memory for a person struct and return a pointer
person* allocate_person(void) {
    person* new_person; // Declare a pointer to a person struct

    // Allocate memory for the person struct using malloc
    new_person = (person*) malloc(sizeof(person));
    if (new_person == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    // Initialize the new person's age to 0
    new_person->age = 0;

    // Set the name to an empty string
    strcpy(new_person->name, "");

    return new_person;
}

// Function to free the memory allocated for a person struct
void free_person(person* person) {
    free(person);
}

int main(void) {
    person* p;

    // Allocate memory for a new person and assign the pointer to p
    p = allocate_person();

    // Access members of the person struct using the -> operator
    p->age = 25;
    strcpy(p->name, "John Doe");

    printf("Person's age: %d\n", p->age);
    printf("Person's name: %s\n", p->name);

    // Free the memory allocated for the person struct
    free_person(p);

    return 0;
}