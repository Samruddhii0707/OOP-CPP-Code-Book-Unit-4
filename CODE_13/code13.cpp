#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fileName;
    ifstream file;

    while (!file.is_open())
    {
        cout << "Enter a valid file name: ";
        cin >> fileName;

        file.open(fileName);

        if (!file)
        {
            cout << "File could not be opened. Try again.\n";
            file.clear();
        }
    }

    cout << "\nFile opened successfully!\n\n";

    string line;

    while (getline(file, line))
    {
        cout << line << endl;
    }

    cout << "\nEOF State: " << file.eof() << endl;
    cout << "Fail State: " << file.fail() << endl;
    cout << "Bad State: " << file.bad() << endl;

    file.close();

    return 0;
}
