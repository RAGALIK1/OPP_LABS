#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class StudentNotFoundException : public std::exception {
private:
    string message;
public:
    explicit StudentNotFoundException(const string& studentName) {
        message = "Student " + studentName + " not found!";
    }

    const char* what() const _NOEXCEPT override { 
        return message.c_str();
    }
};

class InvalidFacultyOperation : public std::exception {
private:
    string message;
public:
    explicit InvalidFacultyOperation(const string& operation) {
        message = "Invalid operation: " + operation + " cannot be performed on this faculty.";
    }

    const char* what() const _NOEXCEPT override { 
        return message.c_str();
    }
};

class Student {
private:
    string name;
    int id;

public:
    Student(const string& studentName, int studentId) : name(studentName), id(studentId) {}

    string getName() const { return name; }
    int getId() const { return id; }
};

class Faculty {
private:
    string name;

public:
    Faculty(const string& facultyName) : name(facultyName) {}

    string getName() const { return name; }

    void performOperation(const string& operation) {
        if (operation == "InvalidOperation") {
            throw InvalidFacultyOperation(operation);
        }
        cout << "Operation " << operation << " performed successfully on faculty " << name << "." << endl;
    }
};

class System {
private:
    Student* students[5];
    int studentCount;

public:
    System() : studentCount(0) {}

    void addStudent(const string& name, int id) {
        if (studentCount < 5) {
            students[studentCount++] = new Student(name, id);
        }
    }

    Student* findStudent(const string& name) {
        for (int i = 0; i < studentCount; ++i) {
            if (students[i]->getName() == name) {
                return students[i];
            }
        }
        throw StudentNotFoundException(name);
    }
};

int main() {
    System system;
    Faculty faculty("Computer Science");

    system.addStudent("John Doe", 1);
    system.addStudent("Jane Smith", 2);

    try {
        Student* student = system.findStudent("Alice Johnson");
        cout << "Student found: " << student->getName() << endl;
    } catch (const StudentNotFoundException& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        faculty.performOperation("InvalidOperation");
    } catch (const InvalidFacultyOperation& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
// g++ -std=c++11 ex7.cpp -o ex7
// ./ex7
