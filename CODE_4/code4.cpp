#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile("message.txt");
    ofstream outputFile("cpp_lines.txt");

    if (!inputFile || !outputFile)
    {
        cout << "File could not be opened.";
        return 1;
    }

    string line;

    while (getline(inputFile, line))
    {
        if (line.find("C++") != string::npos)
        {
            outputFile << line << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Lines containing C++ copied successfully.";

    return 0;
}
