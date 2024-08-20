//  Here is a program of Library Management system using Structures in C++


#include<iostream>
#include<string>

using namespace std;

// Structure of Book
struct Book{
    int bookID;
    string author;
    string title;
    bool isIssued;
};

// Structure of Library
struct Library{
    Book books[100];  //Array to hold a maximum of 100 books
    int no_of_books;  //Number of Books in the Library
};

// Function to add a new book to the library
void addBook(Library &lib) {
    if (lib.no_of_books >= 100) {
        cout << "Library is full, cannot add more books!" << endl;
        return;
    }
    Book newBook;
    cout << "Enter Book ID: ";
    cin >> newBook.bookID;
    cin.ignore(); // To ignore the newline character left in the buffer by cin
    cout << "Enter Book Title: ";
    getline(cin, newBook.title);
    cout << "Enter Book Author: ";
    getline(cin, newBook.author);
    newBook.isIssued = false;

    lib.books[lib.no_of_books] = newBook;
    lib.no_of_books++;
    cout << "Book added successfully!" << endl;
}



// Function to display all books in the library
void displayBooks(const Library &lib) {
    if (lib.no_of_books == 0) {
        cout << "No books in the library.\n"  ;
        return;
    }
    cout << "\nList of Books in the Library:\n";
    for (int i = 0; i < lib.no_of_books; i++) {
        cout << "Book ID: " << lib.books[i].bookID
             << "\nTitle: " << lib.books[i].title
             << "\nAuthor: " << lib.books[i].author
             << "\nStatus: " << (lib.books[i].isIssued ? "Issued" : "Available") <<"\n\n";
    }
}


// Function to search for a book by ID
void searchBook(const Library &lib) {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;
    for (int i = 0; i < lib.no_of_books; i++) {
        if (lib.books[i].bookID == id) {
            cout << "\nBook Details:\n"
                 << "Title: " << lib.books[i].title << "\n"
                 << "Author: " << lib.books[i].author << "\n"
                 << "Status: " << (lib.books[i].isIssued ? "Issued" : "Available") << endl;
            return;
        }
    }
    cout << "Book with ID " << id << " not found!" << endl;
}



// Function to issue a book
void issueBook(Library &lib) {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;
    for (int i = 0; i < lib.no_of_books; i++) {
        if (lib.books[i].bookID == id) {
            if (!lib.books[i].isIssued) {
                lib.books[i].isIssued = true;
                cout << "Book issued successfully!" << endl;
            } else {
                cout << "Book is already issued!" << endl;
            }
            return;
        }
    }
    cout << "Book with ID " << id << " not found!" << endl;
}

// Function to return a book
void returnBook(Library &lib) {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;
    for (int i = 0; i < lib.no_of_books; i++) {
        if (lib.books[i].bookID == id) {
            if (lib.books[i].isIssued) {
                lib.books[i].isIssued = false;
                cout << "Book returned successfully!" << endl;
            } else {
                cout << "Book was not issued!" << endl;
            }
            return;
        }
    }
    cout << "Book with ID " << id << " not found!" << endl;
}

//Making a seperate Function of User Interface...User will interact with only this part in the code. 
void UserInterface()
{
    Library lib;
    lib.no_of_books = 0;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Search Book by ID\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(lib);
                break;
            case 2:
                issueBook(lib);
                break;
            case 3:
                returnBook(lib);
                break;
            case 4:
                displayBooks(lib);
                break;
            case 5:
                searchBook(lib);
                break;
            case 6:
                cout<<"Bye Bye, Thanks for visiting Library Management System\n";
                cout<<"Developed by Sahil Khude\n";
                cout<<endl;
            }
        } while (choice != 6);
}

int main()
{
    UserInterface(); // Calling UI Function to run the application
    return 0;
}