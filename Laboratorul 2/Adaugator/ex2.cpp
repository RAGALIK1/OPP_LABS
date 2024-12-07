#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}
    void displayPerson() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    string studentID;
    string faculty;

public:
    Student(string n = "", int a = 0, string id = "", string f = "")
        : Person(n, a), studentID(id), faculty(f) {}

    void displayStudent() const {
        displayPerson();
        cout << "Student ID: " << studentID << ", Faculty: " << faculty << endl;
    }
};

class Employee {
protected:
    string employeeID;
    string department;

public:
    Employee(string eid = "", string dept = "") : employeeID(eid), department(dept) {}

    void displayEmployee() const {
        cout << "Employee ID: " << employeeID << ", Department: " << department << endl;
    }
};

class StudentEmployee : public Student, public Employee {
private:
    int hoursWorked;

public:
    StudentEmployee(string n, int a, string sid, string fac, string eid, string dept, int hours)
        : Student(n, a, sid, fac), Employee(eid, dept), hoursWorked(hours) {}

    void displayStudentEmployee() const {
        displayStudent();
        displayEmployee();
        cout << "Hours Worked: " << hoursWorked << endl;
    }
};


int main() {
    Student student("Alice", 20, "S123", "Computer Science");
    cout << "Student Details (Single Inheritance):" << endl;
    student.displayStudent();


    cout<<"Partea 2"<<endl<<endl;
    StudentEmployee studentEmployee("Bob", 22, "S124", "Electrical Engineering", "E567", "R&D", 20);

    cout << "\nStudentEmployee Details (Multiple Inheritance):" << endl;
    studentEmployee.displayStudentEmployee();

    return 0;
}
