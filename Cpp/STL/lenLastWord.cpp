#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Hello World       ";
    reverse(s.begin(), s.end());
    int ind;
    for (int i = 0; i < s.length(); i++)
    {
        if (isalpha(s[i]))
        {
            ind = i;
            break;
        }
    }
    int count = 0;
    for (int j = ind; j < s.length(); j++)
    {
        if (s[j] == ' ')
        {
            break;
        }
        count++;
    }
    cout << count;
}