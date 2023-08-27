#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> v = {2, 5, 4, 5, 2};
    int max = *max_element(v.begin(), v.end());
    if (max - k > 0)
    {
        cout << max - k;
    }
    else
    {
        cout << 0;
    }
}