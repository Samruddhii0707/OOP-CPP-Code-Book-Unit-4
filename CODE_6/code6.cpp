#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

string toLowerCase(string text)
{
    for (char &ch : text)
    {
        ch = tolower(ch);
    }

    return text;
}

int main()
{
    ifstream file("message.txt");

    if (!file)
    {
        cout << "File could not be opened.";
        return 1;
    }

    string searchWord;
    string word;
    int count = 0;

    cout << "Enter word to search: ";
    cin >> searchWord;

    searchWord = toLowerCase(searchWord);

    while (file >> word)
    {
        word = toLowerCase(word);

        if (word == searchWord)
        {
            count++;
        }
    }

    file.close();

    cout << "Word found " << count << " time(s).";

    return 0;
}
