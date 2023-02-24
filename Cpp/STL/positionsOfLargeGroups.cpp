#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abbxxxxzzy";
    unordered_map<char, int> m;
    int start_ind = 0, end_ind = 0;
    int cont = 0;
    int arr = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            cont = 1;
        }
        if (cont == 1)
        {
            m[s[i]] += 1;
        }
    }

    // unordered_map<char, int>::iterator it = m.begin();
    // for (pair<char, int> i : m)
    // {
    //     if (i.second < 4)
    //     {
    //         it = m.find(i.first);
    //         m.erase(it);
    //         // continue;
    //         // m.erase(i.first);
    //     }
    //     cout << i.first << " " << i.second << endl;
    // }
    for (pair<char, int> i : m)
    {
        if (i.second >= 4)
        {

            cout << i.first << " " << i.second << endl;
        }
    }
}