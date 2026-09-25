#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("students.txt");
    ofstream tempFile("temp.txt");

    if (!inputFile || !tempFile)
    {
        cout << "File could not be opened.";
        return 1;
    }

    int searchRoll;
    string newName;
    float newMarks;

    cout << "Enter Roll Number to update: ";
    cin >> searchRoll;
    cin.ignore();

    cout << "Enter New Name: ";
    getline(cin, newName);

    cout << "Enter New Marks: ";
    cin >> newMarks;

    string line;
    bool found = false;

    while (getline(inputFile, line))
    {
        stringstream ss(line);

        string roll, name, marks, course, mobile;

        getline(ss, roll, '|');
        getline(ss, name, '|');
        getline(ss, marks, '|');
        getline(ss, course, '|');
        getline(ss, mobile, '|');

        if (stoi(roll) == searchRoll)
        {
            tempFile << roll << "|" << newName << "|"
                     << newMarks << "|" << course
                     << "|" << mobile << endl;

            found = true;
        }
        else
        {
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "Student record updated successfully.";
    else
        cout << "Student record not found.";

    return 0;
}
