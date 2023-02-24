#include <bits/stdc++.h>
using namespace std;

int bin(vector<int> &v, int l, int r, int target)
{
    if (l > r)
    {
        return -1;
    }
    else
    {
        int mid = (l + r) / 2;
        if (v.at(mid) == target)
        {
            return mid;
        }
        else if (target > v.at(mid))
        {
            return bin(v, mid + 1, r, target);
        }
        else
        {
            return bin(v, l, mid - 1, target);
        }
    }
}

int main()
{
    vector<int> nums = {1, 3, 5, 6, 9};
    int target = 2;
    cout << bin(nums, 0, nums.size() - 1, target);
}

// O(n) complexity
//   int main()
//   {
//       vector<int> nums = {1, 3, 5, 6};
//       int target = 2;
//       int pos;
//       for (int i=0 ; i<nums.size() ; i++) {
//           if (nums.at(i)>=target) {
//               pos=i;
//               break;
//           }
//       }
//       cout<<pos;
//   }
