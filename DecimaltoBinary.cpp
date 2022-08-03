#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string DectoBinary(int n)
{
    string s;
    while (n != 0)
    {
        if (n % 2 == 0)
            s.push_back('0');
        else
            s.push_back('1');
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    int n;
    cin >> n;
    cout << DectoBinary(n) << endl;
}