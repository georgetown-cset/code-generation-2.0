#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
    int age;
    int status;
} Person;

int main() {
    // Allocate memory for a new person
    Person *newPerson = (Person *)malloc(sizeof(Person));

    // Set the age and status of the person
    newPerson->age = 25;
    newPerson->status = 0;

    // Print the age and status of the person
    printf("Age: %d\n", newPerson->age);
    printf("Status: %d\n", newPerson->status);

    // Free the allocated memory
    free(newPerson);

    return 0;
}