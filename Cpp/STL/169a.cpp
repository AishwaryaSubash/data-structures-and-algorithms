#include <bits/stdc++.h>
using namespace std;

// Boyer-Moore Voting Algorithm
// Time: O(N); Space: O(1) 

int main() {
    vector<int> nums = {3,2,3};
    int count=0, element=-1;
    for (int i= 0 ; i<nums.size() ; i++) {
        if (count==0)
            element = nums.at(i);
        if (nums.at(i)==element)
            count++;
        else
            count--;
    }

    // If array surely contain a majority element
    cout<<element;

    // Else
    (count>nums.size()/2) ? cout<<element : cout<<-1;
}