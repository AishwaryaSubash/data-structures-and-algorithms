#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1 = {3, 1, 5, 7, 9, 2, 6};
    vector<int> nums2 = {1, 2, 3, 5, 6, 7, 9, 11};
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
    {
        int greater = -1;
        int index;
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1.at(i) == nums2.at(j))
            {
                index = j;
                int k = j;
                while (k != nums2.size())
                {
                    if (nums2.at(j) < nums2.at(k))
                    {
                        greater = nums2.at(k);
                        break;
                    }
                    k++;
                }
            }
        }
        ans.push_back(greater);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }
}