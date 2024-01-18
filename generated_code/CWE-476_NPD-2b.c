
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int status;
    char name[50];

}Person;

int main()
{
  Person *person = (Person*) malloc(sizeof(Person));
  person->status = 0;
  strcpy(person->name, "John");

  // code for cleanup of memory
  free(person);

  return 0;
}
