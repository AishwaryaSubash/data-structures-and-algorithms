#include <bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    return n % 3 == 0 && isPowerOfThree(n / 3);
}

int main()
{
    int n = 3;
    cout << isPowerOfThree(n);
}