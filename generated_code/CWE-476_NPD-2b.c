#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int status;
} Person;

Person* createPerson(char* name, int status) {
    Person* newPerson = (Person*) malloc(sizeof(Person));
    if(newPerson == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newPerson->name = (char*) malloc(strlen(name) + 1);
    if(newPerson->name == NULL) {
        printf("Memory allocation for name failed\n");
        free(newPerson);
        return NULL;
    }
    strcpy(newPerson->name, name);
    newPerson->status = status;
    return newPerson;
}

int main() {
    Person *person;
    person = createPerson("John", 0);
    if(person != NULL) {
        printf("Person Created: %s, %d\n", person->name, person->status);
        free(person->name);
        free(person);
    }
    return 0;
}