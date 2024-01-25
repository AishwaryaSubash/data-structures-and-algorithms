#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int prod = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        prod *= nums.at(i);
    }
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums.at(i) != 0)
            ans.push_back(prod / nums.at(i));
        else
            ans.push_back(prod);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(nums);

    for (int i : ans)
        cout << i << " ";
}