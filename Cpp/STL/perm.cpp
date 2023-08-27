#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> perm(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    ans.push_back(nums);
    while (next_permutation(nums.begin(), nums.end()))
    {
        ans.push_back(nums);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = perm(nums);
    for (vector<int> v : ans)
    {
        for (int i : v)
        {
            cout << i;
        }
        cout << endl;
    }
}