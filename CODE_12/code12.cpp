#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    int rollNo;
    char name[30];
    float marks;
};

int main()
{
    Student students[3] =
    {
        {101, "Samruddhi", 85.5},
        {102, "Vedashri", 90.0},
        {103, "Asmita", 78.5}
    };

    ofstream outFile("records.dat", ios::binary);

    outFile.write((char *)students, sizeof(students));
    outFile.close();

    ifstream inFile("records.dat", ios::binary);

    if (!inFile)
    {
        cout << "File could not be opened.";
        return 1;
    }

    int searchRoll;
    bool found = false;

    cout << "Enter Roll Number to search: ";
    cin >> searchRoll;

    Student s;

    while (inFile.read((char *)&s, sizeof(s)))
    {
        if (s.rollNo == searchRoll)
        {
            cout << "\nRecord Found!" << endl;
            cout << "Roll No: " << s.rollNo << endl;
            cout << "Name: " << s.name << endl;
            cout << "Marks: " << s.marks << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Record not found.";
    }

    inFile.close();

    return 0;
}
