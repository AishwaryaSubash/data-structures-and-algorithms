#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ABFCACDB";
    while (s.find("AB") < s.length() || s.find("CD") < s.length())
    {
        if (s.find("AB") < s.length())
        {
            int i1 = s.find("AB");
            s.erase(i1, 2);
        }
        if (s.find("CD") < s.length())
        {
            int i1 = s.find("CD");
            s.erase(i1, 2);
        }
    }
    cout << s.length();
}