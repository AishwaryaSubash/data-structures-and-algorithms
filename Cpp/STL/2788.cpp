#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> words = {"$easy$", "$problem$"};
    char separator = '$';
    vector<string> v;

    for (int i = 0; i < words.size(); i++)
    {
        string t = "";
        for (char c : words.at(i))
        {
            if (c != separator)
                t.push_back(c);
            if (c == separator && t != "")
            {
                v.push_back(t);
                t.clear();
            }
        }
        if (t != "")
            v.push_back(t);
    }
    for (string u : v)
    {
        cout << u << endl;
    }
}