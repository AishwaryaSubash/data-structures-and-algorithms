#include <bits/stdc++.h>
using namespace std;

// 119. Pascal's Triangle II

// O(m*n)
vector<int> generate(int n)
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

    vector<int> ans;
    int k = n;
    for (int i = 0; i < n + 1; i++)
    {
        // ans.at(i) = grid.at(k).at(i);
        ans.push_back(grid.at(k).at(i));
        k--;
    }

    for (vector<int> i : grid)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    return ans;
}

int main()
{
    vector<int> ans = generate(5);
    for (int i : ans)
        cout << i << " ";
}
