#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 1, 2, 3};
    unordered_map<int, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        m[v.at(i)] += 1;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (m[v.at(i)] == 1)
        {
            cout << v.at(i);
        }
    }
}