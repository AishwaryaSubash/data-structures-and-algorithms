#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ABCDEFGHIJKLIMNOQRSTUVWX";
    int n = 4;
    for (int i = 0; i < s.size(); i += n)
    {
        cout << s.substr(i, n) << endl;
    }
}
