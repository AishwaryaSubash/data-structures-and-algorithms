#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    vector<int> v(n);
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        v.at(i) = val;
    }

    sort(v.begin(), v.end());
    cout << v.at(v.size() - 1);
}
