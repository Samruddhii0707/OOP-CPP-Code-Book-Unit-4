#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream file("message.txt", ios::app);

    if (!file)
    {
        cout << "File could not be opened.";
        return 1;
    }

    string name, date;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter current date: ";
    getline(cin, date);

    file << name << " - " << date << endl;

    file.close();

    cout << "Name and date appended successfully.";

    return 0;
}
