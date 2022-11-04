#include <iostream>
using namespace std;

int prime(int n)
{
    int flag = 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        return 0;
    return 1;
}

int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 3; i <= n; i++){
        if(prime(i)){
            int num = 0;
            for (int j = 2; j <= i; j++){
                if(prime(j)){
                    num += j;
                    if(num == i){
                        count++;
                        break;
                    }
                }
            }
        }
    }
    cout << count;
}