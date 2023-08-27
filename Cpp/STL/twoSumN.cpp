#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {0, 4, 3, 0};
    int target = 0;

    map<int, int> m;
    map<int, int> ind;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums.at(i)] = 1;
        ind[nums.at(i)] = i;
    }
    // pair<int,int>ans;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums.at(i) < target)
        {
            if (m[target - nums.at(i)] == 1 && i != ind[target - nums.at(i)])
            {
                ans.push_back(i);
                ans.push_back(ind[target - nums.at(i)]);
                break;
            }
        }
    }
    for (int i : ans)
    {
        cout << i;
    }
}