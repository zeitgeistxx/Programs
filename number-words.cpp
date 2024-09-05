#include <iostream>
#include <string>
using namespace std;

void generateCharacters(char num)
{
    switch (num)
    {
    case '0':
        cout << "ZERO" << " ";
        break;
    case '1':
        cout << "ONE" << " ";
        break;
    case '2':
        cout << "TWO" << " ";
        break;
    case '3':
        cout << "THREE" << " ";
        break;
    case '4':
        cout << "FOUR" << " ";
        break;
    case '5':
        cout << "FIVE" << " ";
        break;
    case '6':
        cout << "SIX" << " ";
        break;
    case '7':
        cout << "SEVEN" << " ";
        break;
    case '8':
        cout << "EIGHT" << " ";
        break;
    case '9':
        cout << "NINE" << " ";
        break;
    }
}

void numToWord(string s)
{
    // string s = to_string(n);
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        generateCharacters(s[i]);
    }
}

int main()
{
    string n;
    getline(cin, n);

    numToWord(n);
}
