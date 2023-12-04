#include <bits/stdc++.h>
using namespace std;

// 215. Kth Largest Element in an Array
int main()
{
    // O(nlogn) - Heap Sort
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;
    priority_queue<int> q;
    for (int i : nums)
        q.push(i);
    int max = 0;
    while (k > 0)
    {
        max = q.top();
        q.pop();
        k--;
    }
    cout << max;

    // O(n) - 37/41 passed
    // vector<int> nums = {3, 2, 1, 5, 6, 4};
    // int k = 2;
    // int max;
    // while (k > 0)
    // {
    //     max = *max_element(nums.begin(), nums.end());
    //     auto n = find(nums.begin(), nums.end(), max);
    //     if (n != nums.end())
    //     {
    //         nums.erase(n);
    //     }
    //     k--;
    // }
    // cout << max;
}

// INDEX AND ITERATOR
// auto n = find(nums.begin(), nums.end(), max);
// if (n != nums.end())
// {
//     int ind = k - nums.begin();
//     nums.erase(nums.begin() + ind);
//     [or]
//     nums.erase(n);
// }