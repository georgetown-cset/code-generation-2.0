
struct person {
    char name[20];
    int age;
    char gender;
};

struct person *allocate_person() {
    struct person *p;
    p = (struct person *) malloc(sizeof(struct person));
    return p;
}

int main() {
    struct person *p;
    p = allocate_person();
    p->name = "John";
    p->age = 25;
    p->gender = 'M';
    printf("%s %d %c\n", p->name, p->age, p->gender);
    return 0;
}
