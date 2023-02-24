#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    int tmp = 0;
    for (int j = 2; j <= int(n / 2); j++)
    {
        if (n % j == 0)
        {
            tmp++;
            break;
        }
    }
    if (tmp != 0)
    {
        return false; // not prime
    }
    else
    {
        return true;
    }
}
int main()
{
    int n;
    cout << "enter: ";
    cin >> n;
    bool x = false;
    int z = 0;
    for (int i = 2; i <= n; i++)
    {
        if (n == 1 || n == 2 || n == 3 || n == 5)
        {
            x = true;
            z = 1;
            cout << "hi" << endl;
        }

        if (n % i == 0 && isPrime(i) == true)
        {
            x = false;
            z = 0;
            cout << "hiiii" << endl;
            break;
        }
    }
    if (z == 1)
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
}