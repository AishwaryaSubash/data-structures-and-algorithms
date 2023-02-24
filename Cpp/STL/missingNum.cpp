#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    sort(nums.begin(), nums.end());
    int count = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!(nums.at(i) + 1 == nums.at(i + 1) && i != nums.size()))
        {
            count = nums.at(i);
        }
    }
    cout << count;
}