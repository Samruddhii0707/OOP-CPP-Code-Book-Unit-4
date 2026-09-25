#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string fileName;

    cout << "Enter file name: ";
    cin >> fileName;

    ifstream file(fileName);

    if (!file)
    {
        cout << "File could not be opened.";
        return 1;
    }

    int lines = 0;
    int words = 0;
    int characters = 0;
    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;
    int punctuation = 0;

    string line;

    while (getline(file, line))
    {
        lines++;

        bool inWord = false;

        for (char ch : line)
        {
            characters++;

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

            if (!isspace(ch) && !inWord)
            {
                words++;
                inWord = true;
            }
            else if (isspace(ch))
            {
                inWord = false;
            }
        }
    }

    file.close();

    ofstream report("report.txt");

    report << "FILE STATISTICS REPORT\n";
    report << "----------------------\n";
    report << "File Name    : " << fileName << endl;
    report << "Lines        : " << lines << endl;
    report << "Words        : " << words << endl;
    report << "Characters   : " << characters << endl;
    report << "Vowels       : " << vowels << endl;
    report << "Consonants   : " << consonants << endl;
    report << "Digits       : " << digits << endl;
    report << "Spaces       : " << spaces << endl;
    report << "Punctuation  : " << punctuation << endl;

    report.close();

    cout << "Statistics calculated successfully.";
    cout << "\nReport saved in report.txt.";

    return 0;
}
