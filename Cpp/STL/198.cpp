#include <bits/stdc++.h>
using namespace std;

// 198. House Robber

// O(n) - 55/70 [Time Limit Exceeded]
int calc(vector<int> &nums, int i)
{
    if (i < 0)
        return 0;
    return max(calc(nums, i - 2) + nums.at(i), calc(nums, i - 1));
}
int rob(vector<int> &nums)
{
    return calc(nums, nums.size() - 1);
}

// O(n)
int rob(vector<int> &nums)
{

    int even = 0, odd = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
            even += nums.at(i);
        else
            odd += nums.at(i);
    }
    return (even > odd) ? even : odd;
}

// O(n) - 40/70 passed
// int rob(vector<int> &nums)
// {
//     int even = 0, odd = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (i % 2 == 0)
//             even += nums.at(i);
//         else
//             odd += nums.at(i);
//     }
//     return (even > odd) ? even : odd;
// }

int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << rob(nums);
}