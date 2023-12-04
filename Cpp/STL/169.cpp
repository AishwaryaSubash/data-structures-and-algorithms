#include <bits/stdc++.h>
using namespace std;

// 169. Majority Element
int majorityElement(vector<int> &nums)
{
    // O(n)
    // sort(nums.begin(), nums.end());
    // return nums.at(nums.size() / 2);

    // O(n)
    int len = nums.size() / 2;
    map<int, int> m;
    for (int i : nums)
        m[i]++;
    for (int i : nums)
    {
        cout << i << " " << m[i] << endl;
        if (m[i] > len)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums);
}

// TIME LIMIT EXCEEDED
// for (int i : nums)
//     if (count(nums.begin(), nums.end(), i) > nums.size() / 2)
//         return i;