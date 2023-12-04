#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> words = {"alice", "bob", "charlie"};
    string s = "abc";
    string u = "";
    for (string t : words)
    {
        u += t[0];
    }
    cout << (u.compare(s) == 0) ? "true" : "false";
}