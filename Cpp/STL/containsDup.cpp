#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int> nums)
{
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = i + 1; j < nums.size(); j++)
    //     {
    //         if (nums.at(i) == nums.at(j))
    //         {
    //             return true;
    //         }
    //     }
    // }
    // return false;
    set<int> s(nums.begin(), nums.end());
    return s.size() == nums.size();
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << containsDuplicate(nums);
}