#include <stdlib.h>

typedef struct {
    int status;
} person;

person* allocatePerson() {
    // Allocate memory for a new person
    person* newPerson = (person*)malloc(sizeof(person));

    if(newPerson == NULL) {
        // Handle memory allocation failure
        exit(1);
    }

    // Set the status of newPerson to 0
    newPerson->status = 0;

    return newPerson;
}