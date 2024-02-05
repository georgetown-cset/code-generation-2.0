#include <stdlib.h>

typedef struct {
    int status;
    // other members...
} person;

person* allocatePerson() {

    // Allocate memory for a new person
    person* newPerson = malloc(sizeof(person));

    // Check if the memory has been successfully allocated
    if (NULL == newPerson) {
        // Handle malloc failure
        // e.g., print an error message and terminate the program,
        // return an error code, etc.
    }
    else 
    {
        // Set the status to 0
        newPerson->status = 0;
    }
    // return pointer to the allocated 'person'
    return newPerson;
}