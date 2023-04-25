#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "226";
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        vector<int> v;
        for (int j = 1; j <= 2 && j < s.length(); j++)
        {
            string t = s.substr(i, j);
            int n = stoi(t);
            cout << n;
            if (n <= 26 && n >= 1)
            {
                v.push_back(n);
            }
        }
        for (int i : v)
        {
            cout << i << " ";
        }
    }
}