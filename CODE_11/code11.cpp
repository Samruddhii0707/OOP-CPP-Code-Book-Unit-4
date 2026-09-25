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

    ofstream outFile("students.dat", ios::binary);

    if (!outFile)
    {
        cout << "File could not be opened.";
        return 1;
    }

    outFile.write((char *)students, sizeof(students));
    outFile.close();

    ifstream inFile("students.dat", ios::binary);

    if (!inFile)
    {
        cout << "File could not be opened.";
        return 1;
    }

    Student s;

    cout << "Student Records:\n";

    while (inFile.read((char *)&s, sizeof(s)))
    {
        cout << "Roll No: " << s.rollNo << endl;
        cout << "Name: " << s.name << endl;
        cout << "Marks: " << s.marks << endl;
        cout << "-------------------" << endl;
    }

    inFile.close();

    return 0;
}
