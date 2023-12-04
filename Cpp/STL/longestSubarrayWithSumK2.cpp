#include <bits/stdc++.h>
using namespace std;

// Longest Subarray With Sum K
// O(n) - Dynamic Programming
int maxSubArrayWithSumK(vector<int> &nums, int k)
{
     int n = nums.size();
    int maxlen=0;
    for (int i=0 ; i<n ; i++) {
        int sum=0;
        for (int j=i ; j<n ; j++) {
            sum+=nums.at(j);
            if (sum==k) {
                maxlen = max(maxlen, j-i+1);
            }
        }
    }
    return maxlen;
}

int main()
{
    vector<int> nums = {1, 2, 1, 0, 1};
    int k = 4;
    cout << maxSubArrayWithSumK(nums, k);
}


