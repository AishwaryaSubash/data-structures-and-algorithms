#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "226";
    // char A = '1';
    int sum = 0;
    // int n;
    set<vector<int>> v;
    for (int i = 0; i < s.length(); i++)
    {
        vector<int> w;
        for (int j = 1; j <= 2 && j < s.length(); j++)
        {
            string t = s.substr(i, j);
            int n = stoi(t);
            if (n <= 26 && n >= 1)
            {
                w.push_back(n);
            }
            // else
            //     w.clear();
            // continue;
        }
        // for (int o : w)
        // {
        //     cout << o << " ";
        // }
        // cout << endl;

        // w.clear();
        if (!v.empty())
        {
            v.insert(w);
            w.clear();
        }
    }
    // for (vector<int> u : v)
    // {
    cout << v.size();
    // }
}