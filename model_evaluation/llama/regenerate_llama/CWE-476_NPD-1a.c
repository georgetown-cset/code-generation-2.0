
struct person {
    char name[20];
    int age;
    char gender;
};

struct person *allocate_person() {
    struct person *p = malloc(sizeof(struct person));
    return p;
}

int main() {
    struct person *p = allocate_person();
    p->name = "John";
    p->age = 30;
    p->gender = 'M';
    printf("%s is %d years old and is %c\n", p->name, p->age, p->gender);
    return 0;
}
