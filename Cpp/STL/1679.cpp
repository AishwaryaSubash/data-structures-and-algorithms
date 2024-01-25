#include <bits/stdc++.h>
using namespace std;

int maxOperations(vector<int> &nums, int k)
{
    int count = 0;
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        if (nums.at(left) > k)
            left++;
        if (nums.at(right) > k)
            right--;
        if (nums.at(left) + nums.at(right) == k)
        {
            count++;
            left++, right--;
        }
        else
        {
            nums.at(left) < nums.at(right) ? left++ : right--;
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {4, 4, 1, 3, 1, 3, 2, 2, 5, 5, 1, 5, 2, 1, 2, 3, 5, 4};
    int k = 2;
    cout << maxOperations(nums, k);
}