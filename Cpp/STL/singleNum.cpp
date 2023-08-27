#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2, 2, 1};
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums.at(i)]++;
    }
    map<int, int>::iterator it = m.begin();
    while (it != m.end())
    {
        // if (it.second == 1)
        //     cout << it.first;
        break;
    }
}