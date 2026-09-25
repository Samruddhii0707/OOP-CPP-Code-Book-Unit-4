#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main()
{
    ifstream file("message.txt");

    if (!file)
    {
        cout << "File could not be opened.";
        return 1;
    }

    char ch;
    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;
    int punctuation = 0;

    while (file.get(ch))
    {
        if (isalpha(ch))
        {
            char lower = tolower(ch);

            if (lower == 'a' || lower == 'e' ||
                lower == 'i' || lower == 'o' ||
                lower == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
        else if (isdigit(ch))
        {
            digits++;
        }
        else if (isspace(ch))
        {
            spaces++;
        }
        else if (ispunct(ch))
        {
            punctuation++;
        }
    }

    file.close();

    cout << "Vowels       : " << vowels << endl;
    cout << "Consonants   : " << consonants << endl;
    cout << "Digits       : " << digits << endl;
    cout << "Spaces       : " << spaces << endl;
    cout << "Punctuation  : " << punctuation << endl;

    return 0;
}
