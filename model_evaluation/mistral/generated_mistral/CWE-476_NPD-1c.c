#include <stdio.h>
#include <stdlib.h>

// Define the struct type
typedef struct {
    int age;
    char name[30];
    int status;
} person;

int main() {
    person *new_person; // Declare a pointer to a person

    // Allocate memory for a new person and assign the pointer
    new_person = (person *) malloc(sizeof(person));
    if (new_person == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize the new person
    new_person->age = 0;
    strcpy(new_person->name, "");
    new_person->status = 0;

    // Use the new person
    // ...

    // Free the memory when done
    free(new_person);

    return 0;
}