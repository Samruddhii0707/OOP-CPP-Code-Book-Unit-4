#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file("message.txt");

    if (!file)
    {
        cout << "File could not be opened.";
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(file, line))
    {
        cout << lineNumber << ". " << line << endl;
        lineNumber++;
    }

    file.close();

    return 0;
}
