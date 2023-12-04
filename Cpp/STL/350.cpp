#include <bits/stdc++.h>
using namespace std;

// 350. Intersection of Two Arrays II

// O(n)
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    map<int, int> m1;
    map<int, int> m2;
    for (int i : nums1)
        m1[i]++;
    for (int i : nums2)
        m2[i]++;
    for (pair<int, int> p : m1)
    {
        int count = 0;
        if (m2.find(p.first) != m2.end())
        {
            count = min(m1[p.first], m2[p.first]);
            cout << p.first << " " << count;
        }
        while (count > 0)
        {
            ans.push_back(p.first);
            count--;
        }
    }
    return ans;
}

// vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
// {
//     vector<int> ans;
//     for (int p : nums1)
//     {
//         auto k = find(nums2.begin(), nums2.end(), p);
//         cout << *k << endl;
//         if (k != nums2.end())
//         {
//             nums2.erase(k);
//             ans.push_back(p);
//         }
//     }
//     return ans;
// }

int main()
{
    vector<int> nums1 = {1, 4, 2, 1}, nums2 = {2, 5};
    vector<int> ans = intersect(nums1, nums2);
}