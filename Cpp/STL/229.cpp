#include <bits/stdc++.h>
using namespace std;

// Boyer-Moore Voting Algorithm
// Time: O(N); Space: O(1) 

int main() {
    vector<int> nums = {3,2,3};
    int count1=0, element1=-1, count2=0, element2=-1;
    for (int i= 0 ; i<nums.size() ; i++) {
        if (count1==0 && nums.at(i)!=element2) 
            element1 = nums.at(i);
        if (count2==0 && nums.at(i)!=element1) 
            element2 = nums.at(i);

        if (nums.at(i)==element1)
            count1++;
        else if (nums.at(i)==element2)
            count2++;
        else
            count1--, count2--;
    }

    vector<int> ans;
    // if (element1!=-1 && count1>nums.size()/3)
    //     ans.push_back(element1);
    // if (element2!=-1 && count2>nums.size()/3)
    //     ans.push_back(element2);

    count1 = 0, count2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums.at(i) == element1) count1++;
        if (nums.at(i) == element2) count2++;
    }

    int minimum = int(nums.size() / 3) + 1;
    if (count1 >= minimum) ans.push_back(element1);
    if (count2 >= minimum && element1!=element2) ans.push_back(element2);

    return ans;
}