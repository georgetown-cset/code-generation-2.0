#include <stdlib.h>

// Define the structure 'person'
typedef struct {
    int status;
    // add other members if needed...
} person;

person* allocatePerson() {
    // Allocate memory for a new person instance
    person* newPerson = (person*) malloc(sizeof(person));
    
    // Check if memory allocation was successful
    if(newPerson == NULL){
        fprintf(stderr, "Failed to allocate memory");
        exit(1);
    }

    // Set the initial status of the person to 0
    newPerson->status = 0;

    // Return the pointer to the allocated block
    return newPerson;
}