#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;

class Student {
    string name;
    string studentID;

public:
    Student(string n = "", string id = "") : name(n), studentID(id) {}

    string getName() const { return name; }
    string getStudentID() const { return studentID; }

    void display() const {
        cout << "Student Name: " << name << ", ID: " << studentID << endl;
    }
};

class Faculty {
    string name;
    Student* students[MAX_STUDENTS];
    int studentCount;

public:
    Faculty(string n) : name(n), studentCount(0) {}

    void addStudent(Student* student) {
        if (studentCount < MAX_STUDENTS) {
            students[studentCount++] = student;
        } else {
            cout << "Cannot add more students to faculty " << name << endl;
        }
    }

    void display() const {
        cout << "Faculty: " << name << endl;
        cout << "Students in " << name << ":" << endl;
        for (int i = 0; i < studentCount; i++) {
            students[i]->display();
        }
    }
};

int main() {
    Student s1("Alice", "S101");
    Student s2("Bob", "S102");

    Faculty faculty("Computer Science");

    faculty.addStudent(&s1);
    faculty.addStudent(&s2);

    faculty.display();

    return 0;
}
