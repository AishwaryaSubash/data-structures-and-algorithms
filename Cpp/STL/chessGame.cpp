#include <bits/stdc++.h>
using namespace std;

int main()
{
    string coord = "a1";
    if (coord.front() - 'a' + 1 + int(coord.back()) % 2 == 0)
        cout << true;
    else
        cout << false;

}