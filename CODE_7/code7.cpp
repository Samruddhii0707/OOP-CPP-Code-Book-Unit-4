#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream file("students.txt", ios::app);

    if (!file)
    {
        cout << "File could not be opened.";
        return 1;
    }

    int roll;
    string name, course, mobile;
    float marks;

    cout << "Enter Roll Number: ";
    cin >> roll;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Marks: ";
    cin >> marks;
    cin.ignore();

    cout << "Enter Course Name: ";
    getline(cin, course);

    cout << "Enter Mobile Number: ";
    getline(cin, mobile);

    file << roll << "|" << name << "|" << marks
         << "|" << course << "|" << mobile << endl;

    file.close();

    cout << "Student record saved successfully.";

    return 0;
}
