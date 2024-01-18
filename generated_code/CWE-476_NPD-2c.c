#include <iostream>

// Define the Person struct
struct Person {
    int status;
};

// Function to allocate a new Person
Person* createPerson() {
    // Dynamically allocate a new Person
    Person* newPerson = new Person;

    // Set the status to 0
    newPerson->status = 0;

    return newPerson;
}

int main() {
    // Allocate a new Person
    Person* person = createPerson();

    // Test and see the status
    std::cout << "Person's status: " << person->status << std::endl;

    // Don't forget to deallocate the memory!
    delete person;

    return 0;
}