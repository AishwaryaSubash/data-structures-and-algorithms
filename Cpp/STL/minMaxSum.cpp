#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    sort(v.begin(), v.end());
    long long int low = 0, high = 0;
    for (int i = 0; i < 4; i++)
    {
        low += v.at(i);
        high += v.at(i + 1);
    }
    cout << low << " " << high;
}