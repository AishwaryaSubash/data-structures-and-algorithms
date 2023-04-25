#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "this is a string";
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == ' ')
        {
            s.erase(s.begin() + i, s.begin() + i + 1);
            i--;
            s.insert(s.begin() + i + 1, '-');
        }
    }
    cout << s;
}