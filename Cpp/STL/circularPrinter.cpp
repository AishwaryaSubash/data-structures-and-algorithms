#include <bits/stdc++.h>
using namespace std;

int difference(char c, char d)
{
    int diff = abs(c - d);
    int i1 = 26 - diff;
    if (i1 < diff)
        return i1;
    else
        return diff;
}

int main()
{
    string s = "znmd";
    int count = 0, diff = 0;
    for (int i = 1; i < s.length(); i++)
    {
        diff = difference(s.at(i), s.at(i - 1));
        count += diff;
    }
    diff = difference(s.at(0), 'a');
    count += diff;
    cout << count;
}