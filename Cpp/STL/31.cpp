#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3};
    while (next_permutation(nums.begin(), nums.end()))
    {
        for (int i : nums)
        {
            cout << i << " ";
        }
        break;
    }
}