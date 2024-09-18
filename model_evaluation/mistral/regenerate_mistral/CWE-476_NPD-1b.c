
#include <stdio.h>
#include <stdlib.h>

// Define the person struct
typedef struct {
    int age;
    char name[30];
    int status;
} person;

int main() {
    person *p; // Declare a pointer to person

    // Allocate memory for a new person and assign the pointer
    p = (person *) malloc(sizeof(person));
    if (p == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Set the status field to 0
    p->status = 0;

    // Set other fields as needed
    p->age = 25;
    strcpy(p->name, "John Doe");

    // Use the person as needed
    printf("Person's name: %s\n", p->name);
    printf("Person's age: %d\n", p->age);
    printf("Person's status: %d\n", p->status);

    // Don't forget to free the memory when done
    free(p);

    return 0;
}