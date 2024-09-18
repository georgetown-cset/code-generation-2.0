#include <stdlib.h>

typedef struct {
    int status;
    // other members...
} person;

person* allocate_person() {
    // Allocate memory for a person object
    person* new_person = (person*)malloc(sizeof(person));

    if (new_person == NULL) {
        return NULL;   // unable to allocate memory
    }

    // Set the status to 0
    new_person->status = 0;

    return new_person;
}