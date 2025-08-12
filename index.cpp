#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

Book library[50];  // store up to 50 books
int bookCount = 0;

void addBook() {
    cout << "\nEnter Book ID: ";
    cin >> library[bookCount].id;
    cin.ignore(); // clear input buffer
    cout << "Enter Book Title: ";
    getline(cin, library[bookCount].title);
    cout << "Enter Author Name: ";
    getline(cin, library[bookCount].author);
    bookCount++;
    cout << "Book Added Successfully!\n";
}

void displayBooks() {
    if (bookCount == 0) {
        cout << "\nNo books in library!\n";
        return;
    }
    cout << "\n--- Library Books ---\n";
    for (int i = 0; i < bookCount; i++) {
        cout << "ID: " << library[i].id
             << ", Title: " << library[i].title
             << ", Author: " << library[i].author << endl;
    }
}

void searchBook() {
    int searchId;
    cout << "\nEnter Book ID to search: ";
    cin >> searchId;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            cout << "Book Found!\n";
            cout << "Title: " << library[i].title << "\nAuthor: " << library[i].author << endl;
            return;
        }
    }
    cout << "Book Not Found!\n";
}

int main() {
    int choice;
    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
