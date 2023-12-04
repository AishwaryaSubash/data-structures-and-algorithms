#include <bits/stdc++.h>
using namespace std;

vector<string> split(string s)
{
    vector<string> v;
    string t = "";
    for (char c : s)
    {
        if (c == '.')
        {
            v.push_back(t);
            t.clear();
        }
        else
            t += c;
    }
    v.push_back(t);
    t.clear();
    return v;
}

int main()
{
    string s1 = "256.256.256.256";
    vector<string> v = split(s1);
    int flag = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v.at(i) > to_string(255))
        {
            flag = 1;
            break;
        }
    }
    cout << ((flag == 1) ? "Invalid" : "Valid");
}