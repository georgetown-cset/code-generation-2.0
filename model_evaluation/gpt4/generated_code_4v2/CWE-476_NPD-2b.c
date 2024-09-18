#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int status;
} Person;

Person* createPerson(void) {
    Person *newPerson = (Person *)malloc(sizeof(Person));

    if (newPerson == NULL) {
        // Check if memory allocation succeeded
        return NULL;
    }

    newPerson->name = (char *)malloc(sizeof(char) * 5); // Assuming name "John" is of 4 characters, and 1 additional for null character
    if (newPerson->name == NULL) {
        // Check if memory allocation for the name succeeded
        free(newPerson);  // free the allocated memory for PERSON as we are not able to allocate memory for the name.
        return NULL;
    }

    strcpy(newPerson->name, "John");
    newPerson->status = 0;

    return newPerson;
}