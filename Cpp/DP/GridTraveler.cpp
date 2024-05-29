#include <bits/stdc++.h>
using namespace std;

// Grid Traveler with Memoization
// Time: O(m*n); Space: O(m+n)
int gridTraveler2 (int m, int n, map<vector<int>,int> &memo) {
    if (memo.count({m,n}) > 0) return memo[{m,n}];
    if (memo.count({n,m}) > 0) return memo[{n,m}];
    if (m==0 || n==0) return 0;
    if (m==1 && n==1) return 1; 
    memo[{m+n}] = gridTraveler2(m-1, n, memo) + gridTraveler2(m, n-1, memo);
    return memo[{m+n}];
}

// Grid Traveler Without Memoization
// Time: O(2^(m+n)); Space: O(m+n)
int gridTraveler(int m, int n) {
    if (m==0 || n==0) return 0;
    if (m==1 && n==1) return 1;
    return gridTraveler(m-1, n) + gridTraveler(m, n-1);
}

int main() {
    int m = 23, n = 12;
    map<vector<int>, int> memo;
    cout << gridTraveler2(m, n, memo);
}