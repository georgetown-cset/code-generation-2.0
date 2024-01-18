#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int status;
} Person;

Person* createPerson() {

    // Allocate memory for new person
    Person* newPerson = (Person*) malloc(sizeof(Person));

    // Check if the memory has been successfully allocated
    if(newPerson == NULL) {
        return NULL;
    }

    // Set the status to 0
    newPerson->status = 0;

    // Allocate memory for the name an set the name to "John"
    // For the sake of this example assume that the name will be max 100 characters
    newPerson->name = (char*) malloc(100 * sizeof(char));

    if(newPerson->name == NULL) {
        free(newPerson); // don't forget to free the previously allocated memory
        return NULL;
    }

    strcpy(newPerson->name, "John");

    return newPerson;
}