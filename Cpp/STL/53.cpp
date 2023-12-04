#include <bits/stdc++.h>
using namespace std;

// 53. Maximum Subarray
// O(n) - Dynamic Programming
int maxSubArray(vector<int> &nums)
{
    int max = INT_MIN, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums.at(i);

        if (sum > max)
            max = sum;
        if (sum < 0)
            sum = 0;
    }
    return max;
}

int main()
{
    vector<int> nums = {5, 4, -1, 7, 8};
    cout << maxSubArray(nums);

    // O(n^2) - Bruteforce
    // vector<int> ans;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     int max = -999, sum = 0;
    //     for (int j = i; j < nums.size(); j++)
    //     {
    //         sum += nums.at(j);
    //         if (sum > max)
    //             max = sum;
    //     }
    //     ans.push_back(max);
    // }
    // cout << *max_element(ans.begin(), ans.end());
}

// Kandane's Algorithm - O(n)
// int maxSubArray(vector<int> &nums)
// {
//     int global_max = nums[0], curr_max = nums[0];
//     for (int i = 1; i < nums.size(); ++i)
//     {
//         curr_max = max(nums[i], curr_max + nums[i]);
//         if (curr_max > global_max)
//             global_max = curr_max;
//     }
//     return global_max;
// }

// SAME CODE WITH LENGTH OF SUBARRAY
// int maxSubArray(vector<int> &nums)
// {
//     int max = INT_MIN, sum = 0;
//     int beg = 0, end = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int j = i;
//         sum += nums.at(i);

//         if (sum > max)
//         {
//             max = sum;
//             end = j;
//         }
//         if (sum < 0)
//         {
//             sum = 0;
//             beg = i + 1;
//             j = i;
//         }
//     }
//     cout << beg << " " << end << endl;
//     return max;
// }