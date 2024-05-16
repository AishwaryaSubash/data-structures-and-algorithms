#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Time: O(N); Space: O(1)
    vector<int> nums = {1, 3, 4, 2, 2};
    int slow = nums[0], fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    cout << slow;

    // Time: O(N); Space: O(N)
    // vector<int> nums = {1, 3, 4, 2, 2};
    // map<int, int> m;
    // for (int i : nums)
    // {
    //     m[i]++;
    // }
    // for (pair<int, int> p : m)
    // {
    //     if (p.second > 1)
    //     {
    //         cout << p.first;
    //         break;
    //     }
    // }
}