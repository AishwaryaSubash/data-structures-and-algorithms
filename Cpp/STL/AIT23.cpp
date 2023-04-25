#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> v(n);
    int c;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        v.push_back(c);
    }
    set<int> s(v.begin(), v.end());
    int max1 = -99;
    int max2 = -99;
    int max3 = -99;

    for (int i = 0; i < v.size(); i++)
    {
        if (max1 < v.at(i))
            max1 = v.at(i);
        v.push_back(c);
    }
    if (s.size() < 3)
        cout << max1;
}