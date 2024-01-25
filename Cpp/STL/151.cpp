#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    vector<string> v;
    // remove(s.begin(), s.end(), ' ');
    for (char c : s)
    {
        string t = "";
        if (isalnum(c))
        {
            t += to_string(c);
        }
        else
        {
            if (c == ' ')
            {
                v.push_back(t);
                cout << t;
                t.clear();
            }
        }
    }
    return " ";
}

int main()
{
    string n = " a good     example";
    cout << reverseWords(n);
}