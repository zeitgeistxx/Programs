#include <iostream>
#include <conio.h>
#include <algorithm>
#include <array>
#include <string>
using namespace std;

// Designing console
#define design                                                                                  \
    cout << "\n\n\n\n\n";                                                                       \
    cout << "\t\t\t\t**********WELCOME TO Muhib's SEARCH ENGINE*********" << endl;              \
    cout << "\n\n";                                                                             \
    cout << "\t\t\t\t MAIN FEATURES " << endl;                                                  \
    cout << "\t\t\t\t  *During searching it gives you to suggestions." << endl;                 \
    cout << "\t\t\t\t  *During searching you can press enter and search another word." << endl; \
    cout << "\t\t\t\t  *During searching you can press 0 to exit the program." << endl;         \
    cout << "\n\n\n";

int row = 20;
const int col = 21; // max length of a word

// Input function----(heart of the code)
void input(char word[][col], int row, char arr[], int x)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // To check every time searching column starts from zero
            if (j == 0)
            {
                // If first letter of the my searching word and suggesting word is same
                if (word[i][j] == arr[0])
                {
                    // Check next letters of searching word and suggesting words are same
                    int count = 0;
                    for (int l = j, m = 0; m < arr.length(); l++, m++)
                    {
                        if (word[i][l] == arr[m])
                        {
                            count++;
                        }
                    }

                    // if length of the searching word is equal to word suugesting equality count
                    if (count == arr.length())
                    {
                        cout << "\t\t\t\t    ";

                        // if upper condition is true display the suggesting word to the console
                        for (int k = 0; word[i][k] != '\0'; k++)
                        {
                            cout << word[i][k];
                        }
                        cout << endl;
                    }
                }
            }
        }
    }
}

void functionality(char words[][col], int row)
{
    bool flag = false;
    do
    {
        design;
        cout << "\t\t\t\t*******Search Words here********" << endl;
        cout << "\t\t\t\t    >>";

        char arr[row] = {};
        for (int x = 0; x < col; x++)
        {
            // On every input call design
            arr[x] = getch();
            system("cls");
            design;
            cout << "\t\t\t\t*******Search Words here********" << endl;
            cout << "\t\t\t\t    >>";

            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i];
            }

            // If enter is pressed then refresh the console
            if (arr[x] == 13)
            {
                system("cls");
                cout << "\t\t\t\t>>Enter Pressed:" << endl;
                break;
                x = 0;
            }

            // if input is zero then quit
            if (arr[x] == '0')
            {
                cout << endl;
                cout << "Quiting.............." << endl;
                flag = true;
                break;
            }
            cout << endl;

            // call the main heart of the function to search the words
            input(words, row, arr, x);
        }
    } while (flag == false);
}

int main()
{
    /*Add your possible searching words
    and change the number of rows in global according to it*/
    char words[][col] = {
        "ambulance",
        "antarctica",
        "apply",
        "application",
        "australia",
        "bat",
        "batch",
        "battle",
        "compute",
        "computer",
        "compare",
        "device",
        "develop",
        "developer",
        "system",
        "systemic",
        "systole",
        "function",
        "functional",
        "fucntionality",
        "handle",
        "handler",
        "handling",
        "healer"};

    // searching functionality function
    functionality(words, row);
}