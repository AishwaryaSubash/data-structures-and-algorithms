#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0;
    int maxc = -9;
    for (int i : nums)
    {
        if (i == 0)
            count = 0;
        if (i == 1)
            count++;

        if (maxc < count)
            maxc = count;
    }
    return maxc;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums);
}