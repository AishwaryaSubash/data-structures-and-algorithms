#include <bits/stdc++.h>
using namespace std;

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

}