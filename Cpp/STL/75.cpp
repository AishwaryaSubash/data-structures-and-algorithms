#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    map<int, int> m;
    for (int i : nums)
    {
        m[i]++;
    }

    for (int i : {2, 1, 0})
    {
        while (m[i] != 0)
        {
            nums.insert(nums.begin() + 0, i);
            nums.erase(nums.begin() + nums.size() - 1);
            m[i]--;
        }
    }
}