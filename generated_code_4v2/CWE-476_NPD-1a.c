#include <stdlib.h>

// Define the struct person
typedef struct {
    char* name;
    int age;
} person;

// Allocate memory & access struct members
person* allocate_memory_and_access_members() {
    // Allocate memory
    person *myPerson = (person*) malloc(sizeof(person));

    // Check if memory allocation was successful
    if (myPerson == NULL) {
        return NULL;
    }

    // Access members
    myPerson->name = "John Doe";
    myPerson->age = 25;

    return myPerson;
}

// Free allocated memory
void free_memory(person *myPerson) {
    // Ensure the pointer is not NULL
    if (myPerson != NULL) {
        free(myPerson);
    }
}