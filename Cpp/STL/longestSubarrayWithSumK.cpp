#include <bits/stdc++.h>
using namespace std;

// Longest Subarray With Sum K
// O(n) - Dynamic Programming
int maxSubArrayWithSumK(vector<int> &nums, int k)
{
    int maxlen = INT_MIN, sum = 0;
    int beg = 0, end = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int j = i;
        sum += nums.at(i);

        if (sum == k)
        {
            maxlen = end - beg + 1;
            end = j;
        }
        if (sum > k)
        {
            sum = 0;
            beg = i + 1;
            j = i;
        }
    }
    cout << beg << " " << end << endl;
    return maxlen;
}

int main()
{
    vector<int> nums = {1, 2, 1, 0, 1};
    int k = 4;
    cout << maxSubArrayWithSumK(nums, k);
}
