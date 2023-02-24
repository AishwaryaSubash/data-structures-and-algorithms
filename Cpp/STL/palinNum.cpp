#include <bits/stdc++.h>
using namespace std;

bool palin(int n)
{
    if (n < 0)
    {
        return false;
    }
    else if (n == 0)
    {
        return true;
    }
    else
    {
        long long int m = n;
        long long int sum = 0;
        long long int k = 1;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * k;
            k *= 10;
            n = n / 10;
        }
        if (sum == m)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    int num = 120;
    cout << palin(num);
}