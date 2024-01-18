#include <stdlib.h>

typedef struct {
    int status;
    // Other fields can be added here as necessary
} person;

person* allocate_person() {
    person* new_person = (person*) malloc(sizeof(person));
    // Check if the memory has been properly allocated
    if (new_person == NULL) {
        return NULL;
    }
    new_person->status = 0;
    // Other initializations can be added here as necessary
    return new_person;
}