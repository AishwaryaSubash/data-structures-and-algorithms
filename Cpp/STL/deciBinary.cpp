#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Sorting and finding the largest number in the string using set and vector
    string s = "27346209830709182346";
    set<char> se(s.begin(), s.end());
    vector<char> v(se.begin(), se.end());
    sort(v.begin(), v.end());
    string b = "";
    b += v.back();
    cout << stoi(b);
}