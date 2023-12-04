#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> arr = {"d", "b", "c", "b", "c", "a"};
    int k = 2;
    map<string, int> m;
    for (int i = 0; i < arr.size(); i++)
    {
        m[arr.at(i)]++;
    }
    // for (pair<string, int> p : m)
    // {
    //     cout << p.first << " " << p.second;
    // }
    for (pair<string, int> p : m)
    {
        cout << p.first << endl;
        if (p.second == 1)
        {
            k--;
            cout << k << endl;
            if (k == 0)
                cout << p.first;
        }
    }
}