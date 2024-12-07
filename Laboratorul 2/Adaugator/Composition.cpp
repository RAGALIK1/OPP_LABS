#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 50;

class Book {
    string title;
    string author;

public:
    Book(string t = "", string a = "") : title(t), author(a) {}

    void display() const {
        cout << "Title: " << title << ", Author: " << author << endl;
    }
};

class Library {
    string name;
    Book books[MAX_BOOKS]; 
    int bookCount;

public:
    Library(string n) : name(n), bookCount(0) {}

    void addBook(const Book& book) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount++] = book;
        } else {
            cout << "Library is full, cannot add more books." << endl;
        }
    }

    void display() const {
        cout << "Library: " << name << endl;
        cout << "Books in " << name << ":" << endl;
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
        }
    }
};

int main() {
    Library library("Central Library");

    library.addBook(Book("1984", "George Orwell"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));

    library.display();

    return 0;
}
