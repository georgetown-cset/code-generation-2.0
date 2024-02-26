
#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
    int age;
    char name[30];
    int status;
} person;

person *create_person(void) {
    person *new_person;

    // Allocate memory for new person
    new_person = (person *) malloc(sizeof(person));
    if (new_person == NULL) {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }

    // Initialize new person
    new_person->age = 0;
    new_person->status = 0;

    // Set name to an empty string
    strcpy(new_person->name, "");

    return new_person;
}