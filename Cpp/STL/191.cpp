#include <bits/stdc++.h>
using namespace std;

// 191. Number of 1 Bits
int main()
{
    uint32_t n = 00000000000000000000000000001011;
    int count = 0;
    while (n > 0)
    {
        count += n % 2;
        n = n / 2;
    }
    cout << count;
}