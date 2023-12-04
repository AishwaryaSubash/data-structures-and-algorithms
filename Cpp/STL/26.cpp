#include <bits/stdc++.h>
using namespace std;

// 26. Remove Duplicates from Sorted Array
int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int j = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums.at(i) != nums.at(i - 1))
        {
            nums.at(j) = nums.at(i);
        }
        j++;
    }
    cout << j;
}