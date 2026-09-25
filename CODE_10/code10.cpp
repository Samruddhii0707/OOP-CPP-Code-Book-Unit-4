#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("navigation.txt");

    if (!file)
    {
        cout << "File could not be opened.";
        return 1;
    }

    file.seekg(0, ios::end);

    if (file.tellg() == 0)
    {
        cout << "File is empty.";
        return 0;
    }

    file.seekg(-1, ios::end);

    char lastCharacter;
    file.get(lastCharacter);

    cout << "Last character of file: " << lastCharacter << endl;

    file.close();

    return 0;
}
