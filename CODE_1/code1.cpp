#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream file("notes.txt");

    if (!file)
    {
        cout << "File could not be opened.";
        return 1;
    }

    string line;

    cout << "Enter 3 lines:\n";

    for (int i = 1; i <= 3; i++)
    {
        cout << "Line " << i << ": ";
        getline(cin, line);
        file << line << endl;
    }

    file.close();

    cout << "3 lines written successfully to notes.txt.";

    return 0;
}
