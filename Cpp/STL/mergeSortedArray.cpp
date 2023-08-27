#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    vector<int> ans;
    int m = 3, n = 3;

    // int len = m > n ? m : n;
    int i = 0, j = 0, k = 0;
    while (i + j < m + n)
    {
        if (i < m && j < n)
        {
            if (nums1.at(i) <= nums2.at(j))
            {
                ans.push_back(nums1.at(i++));
            }
            else
            {
                ans.push_back(nums2.at(j++));
            }
        }
        i++, j++;
        // k++;
    }
    for (int a : ans)
    {
        cout << a;
    }
}