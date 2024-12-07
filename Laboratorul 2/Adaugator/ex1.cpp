#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    string uniqueID;
    int credits;
    bool graduated;

public:
    Student(string n = "", string id = "", int c = 0)
        : name(n), uniqueID(id), credits(c), graduated(false) {}

    string getName() const { return name; }
    string getUniqueID() const { return uniqueID; }
    int getCredits() const { return credits; }
    bool isGraduated() const { return graduated; }

    void graduate() { graduated = true; }

    Student& operator++() {
        ++credits;
        return *this;
    }

    Student operator++(int) { 
        Student temp = *this;
        ++credits;
        return temp;
    }

    Student& operator--() {
        if (credits > 0) --credits;
        return *this;
    }

    Student operator--(int) {
        Student temp = *this;
        if (credits > 0) --credits; 
        return temp;
    }

    Student& operator+=(const Student& other) {
        credits += other.credits;
        return *this;
    }

    Student& operator+=(int additionalCredits) { 
        credits += additionalCredits;
        return *this;
    }

    void display() const {
        cout << "Student: " << name
             << ", ID: " << uniqueID
             << ", Credits: " << credits
             << (graduated ? ", Graduated" : ", Not Graduated") << endl;
    }
};
int main() {
    Student s1("Alice", "S123", 30);
    Student s2("Bob", "S124", 20);

    cout << "Initial state:\n";
    s1.display();
    s2.display();

    cout << "\nUnary operator examples:\n";
    ++s1; 
    s1.display();
    s1++; 
    s1.display();
    --s2; 
    s2.display();
    s2--; 
    s2.display();

    cout << "\nBinary operator examples:\n";
    s1 += s2;
    cout << "After s1 += s2:\n";
    s1.display();
    s2.display();

    s1 += 10;
    cout << "After s1 += 10:\n";
    s1.display();

    return 0;
}
