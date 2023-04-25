#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "proGRAM";
    string t = "";
    for (char c : s)
    {
        if (islower(c))
        {
            t += toupper(c);
        }
        if (isupper(c))
        {
            t += tolower(c);
        }
    }
    cout << t;
}