#include <bits/stdc++.h>
using namespace std;
// Happy Number
int main()
{
    int n = 387999;
    int sum = 0;
    while (n)
    {
        sum = 0;
        while (n > 0)
        {
            int dig = n % 10;
            n = n / 10;
            sum += dig * dig;
        }
        n = sum;
        cout << sum << " ";
        if (n == 1)
            return true;
        else if (n == 89 || n == 2 || n == 3)
            return false;
    }
}
