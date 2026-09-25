#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book
{
public:
    int bookId;
    string title;
    string author;
    bool issued;

    Book()
    {
        issued = false;
    }
};

void addBook()
{
    Book b;

    cout << "Enter Book ID: ";
    cin >> b.bookId;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, b.title);

    cout << "Enter Author Name: ";
    getline(cin, b.author);

    ofstream file("library_books.txt", ios::app);

    file << b.bookId << "|" << b.title << "|"
         << b.author << "|" << b.issued << endl;

    file.close();

    cout << "Book added successfully.\n";
}

void displayBooks()
{
    ifstream file("library_books.txt");

    if (!file)
    {
        cout << "No books found.\n";
        return;
    }

    string line;

    cout << "\n===== Library Books =====\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void searchBook()
{
    int id;

    cout << "Enter Book ID: ";
    cin >> id;

    ifstream file("library_books.txt");

    string line;
    bool found = false;

    while (getline(file, line))
    {
        size_t pos = line.find('|');

        if (pos != string::npos)
        {
            int bookId = stoi(line.substr(0, pos));

            if (bookId == id)
            {
                cout << "Book Found:\n";
                cout << line << endl;
                found = true;
                break;
            }
        }
    }

    file.close();

    if (!found)
        cout << "Book not found.\n";
}

void updateIssueStatus(int id, bool status)
{
    ifstream input("library_books.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while (getline(input, line))
    {
        size_t first = line.find('|');

        if (first != string::npos)
        {
            int bookId = stoi(line.substr(0, first));

            if (bookId == id)
            {
                size_t second = line.find('|', first + 1);
                size_t third = line.find('|', second + 1);

                string title = line.substr(first + 1,
                                           second - first - 1);

                string author = line.substr(second + 1,
                                            third - second - 1);

                temp << bookId << "|" << title << "|"
                     << author << "|" << status << endl;

                found = true;
            }
            else
            {
                temp << line << endl;
            }
        }
    }

    input.close();
    temp.close();

    remove("library_books.txt");
    rename("temp.txt", "library_books.txt");

    if (found)
        cout << "Book status updated successfully.\n";
    else
        cout << "Book not found.\n";
}

void issueBook()
{
    int id;

    cout << "Enter Book ID to issue: ";
    cin >> id;

    updateIssueStatus(id, true);
}

void returnBook()
{
    int id;

    cout << "Enter Book ID to return: ";
    cin >> id;

    updateIssueStatus(id, false);
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Library Record Manager =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            cout << "Program ended.";
            break;

        default:
            cout << "Invalid choice.";
        }

    } while (choice != 6);

    return 0;
}
