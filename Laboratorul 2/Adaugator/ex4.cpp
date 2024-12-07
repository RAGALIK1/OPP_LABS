#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) : name(n) {}

    virtual string getRole() const = 0;

    virtual ~Person() {}
};

class Student : public Person {
public:
    Student(string n) : Person(n) {}

    string getRole() const override {
        return "Student";
    }
};

class Teacher : public Person {
public:
    Teacher(string n) : Person(n) {}

    string getRole() const override {
        return "Teacher";
    }
};

void printRole(Person* p) {
    cout << p->getRole() << endl;
}

int main() {
    Person* student = new Student("Alice");
    Person* teacher = new Teacher("Bob");

    cout << "Roles:" << endl;
    printRole(student); 
    printRole(teacher); 


    delete student;
    delete teacher;

    return 0;
}
