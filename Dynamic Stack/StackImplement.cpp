#include <iostream>
#include "Stack.hpp"

int main()
{

    Stack<int> s(5);
    int item;


    while (true)
    {
        cout << "\n\n";
        cout << "1.FULL" << endl;
        cout << "2.EMPTY" << endl;
        cout << "3.PUSH" << endl;
        cout << "4.POP" << endl;
        cout << "5.PEEK" << endl;
        cout << "6.DISPLAY" << endl;
        cout << "Choose an operation -> ";

        int y;
        cin >> y;
        switch (y)
        {
        case 1:
            if (s.isFull())
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;

        case 2:
            if (s.isEmpty())
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;

        case 3:
            cout << "Enter an item to push :";
            cin >> item;
            s.push(item);
            break;

        case 4:
            s.pop();
            break;

        case 5:
            if(s.isEmpty()) cout << "Stack is Empty" << endl;
            else{
                cout << "The top element -> " << s.peek() << endl;
            }
            break;

        case 6:
            if(s.isEmpty()) cout << "Stack is Empty" << endl;
            else{
                cout << "The Stack -> ";
                s.display();
            }
            break;

        default:
            cout << "Invalid Operation" << endl;
            exit(0);
        }
    }
}