#include <stdio.h>
#include <stdlib.h>

typedef struct person {
    int age;
    int status;
} Person;

int main() {
    Person *p;

    // Allocate memory for a person
    p = (Person *)malloc(sizeof(Person));

    // Set the age field of the person
    p->age = 25;

    // Set the status field of the person
    p->status = 0;

    // Print the age and status of the person
    printf("Age: %d\n", p->age);
    printf("Status: %d\n", p->status);

    // Free the allocated memory
    free(p);

    return 0;
}