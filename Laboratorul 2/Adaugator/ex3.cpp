#include <iostream>
#include <string>
using namespace std;

const int MAX_PEOPLE = 10;

class Person {
protected:
    string name;

public:

    Person(string n) : name(n) {}

    virtual string getRole() const = 0;

    virtual ~Person() {}

    void display() const {
        cout << "Name: " << name << ", Role: " << getRole() << endl;
    }
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

class Administrator : public Person {
public:
    Administrator(string n) : Person(n) {}

    string getRole() const override {
        return "Administrator";
    }
};
int main() {
    Person* people[MAX_PEOPLE];
    int personCount = 0;       

    if (personCount < MAX_PEOPLE) {
        people[personCount++] = new Student("Alice");
    }
    if (personCount < MAX_PEOPLE) {
        people[personCount++] = new Teacher("Bob");
    }
    if (personCount < MAX_PEOPLE) {
        people[personCount++] = new Administrator("Charlie");
    }

    cout << "Roles in the system:\n";
    for (int i = 0; i < personCount; i++) {
        people[i]->display();
    }

    for (int i = 0; i < personCount; i++) {
        delete people[i];
    }

    return 0;
}
