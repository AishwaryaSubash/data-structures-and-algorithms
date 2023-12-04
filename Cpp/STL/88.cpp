#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1 = {2, 0}, nums2 = {1};

    // O(n)
    int m = 1, n = 1;
    for (int j = 0, i = m; j < n; j++, i++)
    {
        nums1[i] = nums2[j];
    }
    sort(nums1.begin(), nums1.end());

    // O(n)
    // int i = m - 1, j = n - 1, k = m + n - 1;
    // while (j >= 0)
    // {
    //     if (i >= 0 && nums1[i] > nums2[j])
    //         nums1[k--] = nums1[i--];
    //     else
    //         nums1[k--] = nums2[j--];
    // }

    for (int i : nums1)
        cout << i << " ";
}