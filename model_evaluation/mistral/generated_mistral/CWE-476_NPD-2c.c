#include <stdio.h>
#include <stdlib.h>

// Define the structure Person
typedef struct {
    int status; // Status of the person
    char name[50]; // Name of the person
} Person;

// Function to allocate memory for a new Person and initialize the status
Person* create_person() {
    Person* new_person; // Pointer to new Person

    // Allocate memory for the new Person
    new_person = (Person*) malloc(sizeof(Person));
    if (new_person == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    // Initialize the status of the new Person
    new_person->status = 0;

    return new_person;
}

// Function to print the details of a Person
void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Status: %d\n", person->status);
}

int main() {
    Person* new_person; // Pointer to new Person

    // Allocate memory for a new Person and initialize the status
    new_person = create_person();

    // Set the name of the new Person
    strcpy(new_person->name, "John Doe");

    // Print the details of the new Person
    print_person(new_person);

    // Free the allocated memory
    free(new_person);

    return 0;
}