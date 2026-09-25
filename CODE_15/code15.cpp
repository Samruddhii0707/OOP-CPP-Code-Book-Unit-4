#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Student
{
    int roll;
    string name;
    float marks;
    char grade;
    string course;
    string department;
};

void addStudent()
{
    Student s;

    cout << "Enter Roll Number: ";
    cin >> s.roll;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Marks: ";
    cin >> s.marks;
    cin.ignore();

    cout << "Enter Grade: ";
    cin >> s.grade;
    cin.ignore();

    cout << "Enter Course: ";
    getline(cin, s.course);

    cout << "Enter Department: ";
    getline(cin, s.department);

    ofstream file("student_manager.txt", ios::app);

    file << s.roll << "|" << s.name << "|" << s.marks
         << "|" << s.grade << "|" << s.course
         << "|" << s.department << endl;

    file.close();

    cout << "Student added successfully.\n";
}

void displayStudents()
{
    ifstream file("student_manager.txt");

    if (!file)
    {
        cout << "No records found.\n";
        return;
    }

    string line;

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void searchStudent()
{
    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;

    ifstream file("student_manager.txt");

    string line;
    bool found = false;

    while (getline(file, line))
    {
        stringstream ss(line);

        string rollStr;
        getline(ss, rollStr, '|');

        if (stoi(rollStr) == roll)
        {
            cout << "Record Found:\n";
            cout << line << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Student not found.\n";
}

void updateMarks()
{
    int roll;
    float newMarks;

    cout << "Enter Roll Number: ";
    cin >> roll;

    cout << "Enter New Marks: ";
    cin >> newMarks;

    ifstream input("student_manager.txt");
    ofstream temp("temp.txt");

    string line;
    bool found = false;

    while (getline(input, line))
    {
        stringstream ss(line);

        string rollStr, name, marks, grade, course, department;

        getline(ss, rollStr, '|');
        getline(ss, name, '|');
        getline(ss, marks, '|');
        getline(ss, grade, '|');
        getline(ss, course, '|');
        getline(ss, department, '|');

        if (stoi(rollStr) == roll)
        {
            temp << rollStr << "|" << name << "|"
                 << newMarks << "|" << grade << "|"
                 << course << "|" << department << endl;

            found = true;
        }
        else
        {
            temp << line << endl;
        }
    }

    input.close();
    temp.close();

    remove("student_manager.txt");
    rename("temp.txt", "student_manager.txt");

    if (found)
        cout << "Marks updated successfully.\n";
    else
        cout << "Student not found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Student Record Manager =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Marks\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateMarks();
            break;

        case 5:
            cout << "Program ended.";
            break;

        default:
            cout << "Invalid choice.";
        }

    } while (choice != 5);

    return 0;
}
