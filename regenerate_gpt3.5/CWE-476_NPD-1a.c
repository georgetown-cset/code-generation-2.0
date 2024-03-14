// Define a struct for a person
typedef struct {
    char name[50];
    int age;
} person;

// Function to allocate memory for a person struct
person* allocate_memory() {
    person* ptr = (person*) malloc(sizeof(person));
    return ptr;
}

// Example of how to use the allocate_memory function
int main() {
    person* new_person = allocate_memory();
    
    if (new_person == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }
    
    // Accessing and setting values using the -> operator
    strcpy(new_person->name, "John Doe");
    new_person->age = 30;
    
    // Print out values
    printf("Name: %s\n", new_person->name);
    printf("Age: %d\n", new_person->age);
    
    // Free allocated memory
    free(new_person);
    
    return 0;
}