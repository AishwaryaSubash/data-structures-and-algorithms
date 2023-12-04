#include <bits/stdc++.h>
using namespace std;

// 118. Pascal's Triangle

// O(m*n)
vector<vector<int>> generate(int n)
{
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < n + 1; i++)
        grid.at(i).at(0) = 1;
    for (int i = 0; i < n + 1; i++)
        grid.at(0).at(i) = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j + i < n + 1; j++)
        {
            grid.at(i).at(j) = grid.at(i - 1).at(j) + grid.at(i).at(j - 1);
        }
    }

    vector<vector<int>> ans;

    for (int j = 0; j < n; j++)
    {
        int k = j, i = 0;
        vector<int> v;
        while (k >= 0)
        {
            v.push_back(grid.at(k--).at(i++));
        }
        ans.push_back(v);
        v.clear();
    }

    // for (vector<int> i : grid)
    // {
    //     for (int j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for (vector<int> i : ans)
    // {
    //     for (int j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }

    return ans;
}

int main()
{
    vector<vector<int>> ans = generate(5);
}
