#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    int sum = 0, rsum = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
        rsum -= nums.at(i);
        if (sum == rsum)
            return i;
        sum += nums.at(i);
    }

    return -1;
}

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << pivotIndex(nums);
}