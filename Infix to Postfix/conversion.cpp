#include <iostream>
#include <stack>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

void infixToPostfix(string s)
{

    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // If the scanned character is an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result.push_back(c);

        // If the scanned character is an '(', push it to the stack.
        else if (c == '(')
            st.push(c);

        // If the scanned character is an ')', pop to output string from the stack until ‘(‘ is encountered.
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result.push_back(st.top());
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                if (c == '^' && st.top() != '^')
                    break;
                else
                {
                    result.push_back(st.top());
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    cout << result << endl;
}

int main()
{
    string s;
    cin >> s;

    infixToPostfix(s);
}