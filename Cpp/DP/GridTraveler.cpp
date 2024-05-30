#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memory;

// Grid Traveler with Memoization
// Time: O(m*n); Space: O(m+n)
int dp[101][101]{};
int gridTraveler3(int m, int n, int i = 0, int j = 0) {
    if(i >= m || j >= n) return 0;
    if(i == m-1 && j == n-1) return 1;
    if(dp[i][j]) return dp[i][j];
    return dp[i][j] = gridTraveler3(m, n, i+1, j) + gridTraveler3(m, n, i, j+1);
}
// int gridTraveler3 (int m, int n, int i=0, int j=0) {
//     if (i>=m || j>=n) return 0;
//     if (i==m-1 && j==n-1) return 1;
//     if (memory.at(i).at(j)) return memory.at(i).at(j);
//     return memory.at(i).at(j) = gridTraveler3(m,n,i+1,j) + gridTraveler3(m,n,i,j+1);
// }

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
    int m = 3, n = 7;
    map<vector<int>, int> memo;
    cout << gridTraveler3(m, n);
}