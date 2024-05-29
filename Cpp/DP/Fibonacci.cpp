#include <bits/stdc++.h>
using namespace std;

// Fibonacci with memoization
// Time: O(n); Space: O(n)
int fib (int n, map<int, long long> &memo) {
    if (memo.count(n)>0) return memo[n];
    if (n<=2) return 1;
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
}

int main() {
    int n = 26;
    map<int, long long> memo;
    cout << fib(n, memo);
}