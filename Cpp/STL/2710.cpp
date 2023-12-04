#include <bits/stdc++.h>
using namespace std;

// Remove Trailing Zeros From a String
int main()
{
    string num = "51230100000";
    int c = num.length() - 1;

    while (c >= 0 && num[c] == '0')
        c--;
    if (c < 0)
        cout << "";
    cout << num.substr(0, c + 1);
}