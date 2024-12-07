#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_FACULTIES = 10; 

class Person {
protected:
    string name;
    string uniqueID;
public:
    Person(string n = "", string id = "") : name(n), uniqueID(id) {}
    string getName() const { return name; }
    string getUniqueID() const { return uniqueID; }
};

class Student : public Person {
    bool graduated;
public:
    Student(string n = "", string id = "") : Person(n, id), graduated(false) {}
    bool isGraduated() const { return graduated; }
    void graduate() { graduated = true; }
};

class Faculty {
    string name;
    string field;
    Student students[MAX_STUDENTS];
    int studentCount;
public:
    Faculty(string n = "", string f = "") : name(n), field(f), studentCount(0) {}

    string getName() const { return name; }
    string getField() const { return field; }

    void addStudent(const Student& student) {
        if (studentCount < MAX_STUDENTS) {
            students[studentCount++] = student;
        } else {
            cout << "Faculty " << name << " is full, cannot add more students.\n";
        }
    }

    void graduateStudent(const string& studentID) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getUniqueID() == studentID) {
                students[i].graduate();
                return;
            }
        }
        cout << "Student not found in " << name << " faculty.\n";
    }

    void displayCurrentStudents() const {
        cout << "Current students in " << name << ":\n";
        for (int i = 0; i < studentCount; i++) {
            if (!students[i].isGraduated()) {
                cout << "- " << students[i].getName() << " (ID: " << students[i].getUniqueID() << ")\n";
            }
        }
    }

    void displayGraduates() const {
        cout << "Graduates from " << name << ":\n";
        for (int i = 0; i < studentCount; i++) {
            if (students[i].isGraduated()) {
                cout << "- " << students[i].getName() << " (ID: " << students[i].getUniqueID() << ")\n";
            }
        }
    }

    bool hasStudent(const string& studentID) const {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getUniqueID() == studentID) {
                return true;
            }
        }
        return false;
    }
};

class University {
    Faculty faculties[MAX_FACULTIES];
    int facultyCount;
public:
    University() : facultyCount(0) {}

    void createFaculty(const string& name, const string& field) {
        if (facultyCount < MAX_FACULTIES) {
            faculties[facultyCount++] = Faculty(name, field);
        } else {
            cout << "University has reached the maximum number of faculties.\n";
        }
    }

    void assignStudentToFaculty(const string& facultyName, const Student& student) {
        for (int i = 0; i < facultyCount; i++) {
            if (faculties[i].getName() == facultyName) {
                faculties[i].addStudent(student);
                return;
            }
        }
        cout << "Faculty " << facultyName << " not found.\n";
    }

    void graduateStudent(const string& studentID) {
        for (int i = 0; i < facultyCount; i++) {
            if (faculties[i].hasStudent(studentID)) {
                faculties[i].graduateStudent(studentID);
                return;
            }
        }
        cout << "Student with ID " << studentID << " not found.\n";
    }

    void displayFaculties() const {
        cout << "Faculties in the University:\n";
        for (int i = 0; i < facultyCount; i++) {
            cout << "- " << faculties[i].getName() << " (" << faculties[i].getField() << ")\n";
        }
    }

    void displayFacultiesByField(const string& field) const {
        cout << "Faculties in the field " << field << ":\n";
        for (int i = 0; i < facultyCount; i++) {
            if (faculties[i].getField() == field) {
                cout << "- " << faculties[i].getName() << " (" << faculties[i].getField() << ")\n";
            }
        }
    }

    void displayStudentsInFaculty(const string& facultyName, bool graduates = false) const {
        for (int i = 0; i < facultyCount; i++) {
            if (faculties[i].getName() == facultyName) {
                if (graduates) {
                    faculties[i].displayGraduates();
                } else {
                    faculties[i].displayCurrentStudents();
                }
                return;
            }
        }
        cout << "Faculty " << facultyName << " not found.\n";
    }

    void findStudentFaculty(const string& studentID) const {
        for (int i = 0; i < facultyCount; i++) {
            if (faculties[i].hasStudent(studentID)) {
                cout << "Student with ID " << studentID << " belongs to faculty: " << faculties[i].getName() << "\n";
                return;
            }
        }
        cout << "Student with ID " << studentID << " not found.\n";
    }
};

int main() {
    University tum;

    tum.createFaculty("Computer Science", "Technology");
    tum.createFaculty("Food Technology", "Food Science");

    Student student1("Alice", "S123");
    Student student2("Bob", "S124");

    tum.assignStudentToFaculty("Computer Science", student1);
    tum.assignStudentToFaculty("Food Technology", student2);

    tum.displayFaculties();

    tum.displayStudentsInFaculty("Computer Science");

    tum.graduateStudent("S123");

    tum.displayStudentsInFaculty("Computer Science", true);

    tum.findStudentFaculty("S124");

    return 0;
}
