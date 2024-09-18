#include <stdio.h>
#include <stdlib.h>

// Define person structure
struct person {
    int status;
};

// Function to allocate memory and set status
struct person* allocate_person() {
    struct person* new_person = (struct person*) malloc(sizeof(struct person));
    if (new_person == NULL) {
        printf("Failed to allocate memory\n");
        exit(1);
    }
    new_person->status = 0;
    return new_person;
}

int main() {
    struct person* person_ptr = allocate_person();

    printf("Person status: %d\n", person_ptr->status);

    // remember to free the allocated memory
    free(person_ptr); 

    return 0;
}