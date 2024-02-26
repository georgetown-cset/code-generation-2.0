#include <stdio.h>
#include <stdlib.h> // For malloc()

// Define the struct type
typedef struct Person {
    int status;
    char name[20];
} Person;

// Function to create a new person and return a pointer to it
Person* createPerson(char* name) {
    Person* newPerson; // Declare a pointer to Person

    // Allocate memory for the new person
    newPerson = (Person*) malloc(sizeof(Person));
    if (newPerson == NULL) { // Check if memory allocation was successful
        printf("Error: Could not allocate memory.\n");
        return NULL;
    }

    // Set the name and status of the new person
    strcpy(newPerson->name, name);
    newPerson->status = 0;

    return newPerson; // Return the pointer to the newly created person
}

// Function to print the status and name of a person
void printPerson(Person* person) {
    printf("Status: %d, Name: %s\n", person->status, person->name);
}

int main() {
    Person* john; // Declare a pointer to Person

    // Create a new person named "John"
    john = createPerson("John");
    if (john != NULL) { // Check if memory allocation was successful
        printPerson(john);
        free(john); // Free the memory when done
    }

    return 0;
}