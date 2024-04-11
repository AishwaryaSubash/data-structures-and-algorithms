#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.at(i).size(); j++)
        {
            if (i == j || j == 0)
            {
                grid.at(i).at(j) = 1;
            }
        }
    }

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (grid.at(i).at(j) != 1)
            {
                grid.at(i).at(j) = grid.at(i - 1).at(j) + grid.at(i - 1).at(j - 1);
            }
        }
    }

    vector<vector<int>> ans;
    for (int i = 0; i < grid.size(); i++)
    {
        vector<int> v;
        for (int j = 0; j < grid.at(i).size(); j++)
        {
            if (grid.at(i).at(j) != 0)
            {
                v.push_back(grid.at(i).at(j));
            }
        }
        ans.push_back(v);
        v.clear();
    }

    for (vector<int> p : ans)
    {
        for (int i : p)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}