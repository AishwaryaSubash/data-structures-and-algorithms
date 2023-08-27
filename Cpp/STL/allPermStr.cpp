#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcd";
    int c = 0;
    vector<string> v;
    while (next_permutation(s.begin(), s.end()))
    {
        v.push_back(s);
        // cout << s << endl;
        c++;
    }
    cout << c;
    for (string t : v)
    {
        cout << t << endl;
    }
}