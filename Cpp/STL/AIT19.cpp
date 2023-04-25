#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n = 0;
    while (next_permutation(s.begin(), s.end()))
    {
        n++;
    }
    cout << n;
}
