#include <bits/stdc++.h>
using namespace std;

// 344. Reverse String
int main()
{
    vector<string> s = {"h", "e", "l", "l", "o"};
    int l = 0, r = s.size() - 1;
    while (l <= r)
    {
        string temp = s.at(l);
        s.at(l) = s.at(r);
        s.at(r) = temp;
        l++;
        r--;
    }
}