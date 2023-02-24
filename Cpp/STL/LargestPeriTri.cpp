#include <bits/stdc++.h>
using namespace std;

int peri(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 3; i >= 0; i--)
    {
        if (nums.at(i) + nums.at(i + 1) > nums.at(i + 2))
        {
            return nums.at(i) + nums.at(i + 1) + nums.at(i + 2);
        }
    }
    return 0;
}

int main()
{
    vector<int> nums = {2, 1, 2};

    cout << peri(nums);
}
