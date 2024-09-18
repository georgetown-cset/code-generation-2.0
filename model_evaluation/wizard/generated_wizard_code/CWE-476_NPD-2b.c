#include <stdio.h>
#include <stdlib.h>

// Define the structure of a person
typedef struct Person {
    int status;
    char *name;
} Person;

// Function to allocate memory for a person
Person *createPerson() {
    Person *p;
    p = (Person *) malloc(sizeof(Person));
    p->status = 0;
    p->name = (char *) malloc(6 * sizeof(char));
    strcpy(p->name, "John");
    return p;
}

int main() {
    // Create a new person
    Person *person = createPerson();

    // Access the members of the person struct
    printf("Status: %d\n", person->status);
    printf("Name: %s\n", person->name);

    // Free the allocated memory
    free(person->name);
    free(person);

    return 0;
}