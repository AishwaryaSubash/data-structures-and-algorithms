#include <bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int> &gain)
{
    vector<int> alt;
    alt.push_back(0);
    for (int i = 1; i < gain.size() + 1; i++)
        alt.push_back(alt.at(i - 1) + gain.at(i - 1));
    return *max_element(alt.begin(), alt.end());
}

int main()
{
    vector<int> gain = {-5, 1, 5, 0, -7};
    cout << largestAltitude(gain);
}