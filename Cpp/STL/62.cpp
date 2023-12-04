#include <bits/stdc++.h>
using namespace std;

// 62. Grid Traveller/ Unique Paths

// O(m*n)
int uniquePaths(int m, int n)
{
    vector<vector<int>> grid(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
        grid.at(i).at(0) = 1;
    for (int i = 0; i < n; i++)
        grid.at(0).at(i) = 1;

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            grid.at(i).at(j) = grid.at(i - 1).at(j) + grid.at(i).at(j - 1);
        }
    }

    for (vector<int> i : grid)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    return grid.at(m - 1).at(n - 1);
}

int main()
{
    cout << uniquePaths(51, 9) << endl;
}

// O(2^(m+n))

// int uniquePaths(int m, int n) {
//         if (m==1 && n==1) return 1;
//         if (m==0 || n==0) return 0;
//         return uniquePaths(m-1,n) + uniquePaths(m,n-1);
// }