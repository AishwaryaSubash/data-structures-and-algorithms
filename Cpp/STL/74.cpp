#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m=mat.size(), n=mat.at(0).size();
    int l=0, r=m*n-1;
    while (l<=r) {
        int mid = (l+r)/2;
        if (mat.at(mid/n).at(mid%n)==target)
            return true;
        else if (mat.at(mid/n).at(mid%n)>target)
            r = mid-1;
        else
            l = mid+1;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 11;
    cout<<searchMatrix(matrix, target);
    return 0;
}