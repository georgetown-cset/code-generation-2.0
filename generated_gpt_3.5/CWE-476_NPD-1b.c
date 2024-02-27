#include <stdlib.h>

typedef struct {
    int status;
    // You can add here more attributes of Person (Such as name, address, etc.)
} person;

person* allocatePerson() {
    // Allocate Memory of size equal to a person object
    person* newPerson = (person*) malloc(sizeof(person));

    // Check if memory allocation was successful
    if (newPerson == NULL) {
        printf("Failed to allocate memory for new person\n");
        exit(1); // Exit program with error code 1
    }

    // Set the status field to 0
    newPerson->status = 0;

    // Return pointer to the allocated block
    return newPerson;
}

int main() {
    // Allocate a new person and get a pointer to it
    person* p = allocatePerson();

    // Use person*

    // Don't forget to free the allocated memory once you're done!
    free(p);

    return 0;
}