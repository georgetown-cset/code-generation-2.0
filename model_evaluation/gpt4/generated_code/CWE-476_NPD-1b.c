#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int status;
} person;

person *allocatePerson() {
    person *new_person = (person *)malloc(sizeof(person));
    if (new_person == NULL) {
        printf("Failed to allocate memory.\n");
        return NULL;
    }

    new_person->status = 0;

    return new_person;
}

int main() {
    person *my_person = allocatePerson();
    if (my_person != NULL) {
        printf("Person status: %d\n", my_person->status);
        free(my_person);
    }
    return 0;
}