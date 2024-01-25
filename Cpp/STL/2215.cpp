#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    vector<vector<int>> ans;
    vector<int> a = {}, b = {};

    for (int i = 0; i < nums1.size(); i++)
    {
        if (find(nums2.begin(), nums2.end(), nums1.at(i)) == nums2.end() && find(a.begin(), a.end(), nums1.at(i)) == a.end())
        {
            a.push_back(nums1.at(i));
        }
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        if (find(nums1.begin(), nums1.end(), nums2.at(i)) == nums1.end() && find(b.begin(), b.end(), nums2.at(i)) == b.end())
        {
            b.push_back(nums2.at(i));
        }
    }
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 3}, nums2 = {1, 1, 2, 2};
    vector<vector<int>> ans = findDifference(nums1, nums2);
    for (vector<int> v : ans)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}