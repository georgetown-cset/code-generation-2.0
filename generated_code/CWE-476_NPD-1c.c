#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int status;
    // Other attributes of person if necessary
} person;

person* allocatePerson() {
    person* newPerson = (person*) malloc(sizeof(person));
    if(newPerson == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if the memory allocation failed
    }
    newPerson->status = 0;
    return newPerson;
}

int main() {
    person* somePerson = allocatePerson();
    // Use somePerson variable here
    free(somePerson); // Don't forget to free the memory
    return 0;
}