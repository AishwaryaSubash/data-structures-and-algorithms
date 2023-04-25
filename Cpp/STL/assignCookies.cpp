#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {3};
    sort(g.rbegin(), g.rend());
    sort(s.rbegin(), s.rend());
    int count = 0, i = 0, j = 0;

    while (i < g.size())
    {
        if (j < s.size() && s[j] >= g[i])
        {
            count++;
            j++;
        }
        i++;
    }
    cout << count;
}