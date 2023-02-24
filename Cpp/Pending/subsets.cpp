#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    ans.push_back({});
    ans.push_back(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            
        }
    }
    for (vector<int> w : ans)
    {
        for (int i : w)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}