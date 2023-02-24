#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> nums, int target)
{
    vector<int> ans;
    int flag = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums.at(i) + nums.at(j) == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                flag = 1;
                break;
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
            break;
    }
    if (flag == 1)
        return ans;
    else
        return {-1, -1};
}

int main()
{
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> ans = twoSum(nums, target);
    for (int i : ans)
    {
        cout << i << " ";
    }
}
