#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int status;
};

int main() {
    struct Person *new_person;

    new_person = (struct Person *) malloc(sizeof(struct Person));

    if (new_person == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    new_person->status = 0;
    strcpy(new_person->name, "John");

    printf("Name: %s\n", new_person->name);
    printf("Status: %d\n", new_person->status);

    free(new_person);

    return 0;
}