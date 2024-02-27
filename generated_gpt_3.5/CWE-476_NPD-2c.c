#include <stdio.h>
#include <stdlib.h>

typedef struct person {
    int status;
} person;

person* createPerson() {
    person* new_person = (person*)malloc(sizeof(person));
    if(new_person == NULL) {
        printf("Failed to allocate memory\n");
        exit(1);
    }
    new_person->status = 0;
    return new_person;
}

int main() {
    person* myPerson = createPerson();
    printf("Status: %d\n", myPerson->status);
    free(myPerson);

    return 0;
}