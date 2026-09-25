#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    ifstream file("students.txt");

    if (!file)
    {
        cout << "File could not be opened.";
        return 1;
    }

    string line;

    cout << left
         << setw(10) << "Roll"
         << setw(20) << "Name"
         << setw(10) << "Marks"
         << setw(20) << "Course"
         << setw(15) << "Mobile" << endl;

    cout << string(75, '-') << endl;

    while (getline(file, line))
    {
        stringstream ss(line);

        string roll, name, marks, course, mobile;

        getline(ss, roll, '|');
        getline(ss, name, '|');
        getline(ss, marks, '|');
        getline(ss, course, '|');
        getline(ss, mobile, '|');

        cout << left
             << setw(10) << roll
             << setw(20) << name
             << setw(10) << marks
             << setw(20) << course
             << setw(15) << mobile << endl;
    }

    file.close();

    return 0;
}
