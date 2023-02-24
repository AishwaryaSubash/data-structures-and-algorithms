#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int flag = 0;
    for (int i = 1; i*i <=num; i++)
    {
        if ((num % i == 0) && (num / i == i))
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << true;
    }
    else
    {
        cout << false;
    }
}