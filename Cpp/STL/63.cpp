#include <bits/stdc++.h>
using namespace std;

// 63. Unique Paths II

int uniquePathsWithObstacles(vector<vector<int>> obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid.at(0).size();
    if (obstacleGrid.at(0).at(0) == 1)
        return 0;
    vector<vector<int>> grid(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid.at(i).at(j) == 1)
                grid.at(i).at(j) = 0;
        }
    }
    grid.at(0).at(0) = 1;

    for (int i = 1; i < m; i++)
    {
        if (obstacleGrid.at(i).at(0) != 1 && grid.at(i - 1).at(0) == 1)
            grid.at(i).at(0) = 1;
        else
            grid.at(i).at(0) = 0;
    }
    for (int j = 1; j < n; j++)
    {
        if (obstacleGrid.at(0).at(j) != 1 && grid.at(0).at(j - 1) == 1)
            grid.at(0).at(j) = 1;
        else
            grid.at(0).at(j) = 0;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid.at(i).at(j) == -1)
            {
                grid.at(i).at(j) = grid.at(i - 1).at(j) + grid.at(i).at(j - 1);
            }
        }
    }

    return grid.at(m - 1).at(n - 1);
}

int main()
{
    // vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> obstacleGrid = {{0, 0}, {1, 1}, {0, 0}};
    cout << uniquePathsWithObstacles(obstacleGrid);
}

// OLD ANSWER - 24/41
// class Solution
// {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
//     {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid.at(0).size();
//         if (obstacleGrid.at(0).at(0) == 1)
//             return 0;
//         vector<vector<int>> grid(m, vector<int>(n, 0));
//         for (int i = 0; i < m; i++)
//         {
//             if (obstacleGrid.at(i).at(0) != 1)
//                 grid.at(i).at(0) = 1;
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (obstacleGrid.at(0).at(i) != 1)
//                 grid.at(0).at(i) = 1;
//         }
//         for (int i = 1; i < m; i++)
//         {
//             for (int j = 1; j < n; j++)
//             {
//                 if (obstacleGrid.at(i).at(j) != 1)
//                     grid.at(i).at(j) = grid.at(i - 1).at(j) + grid.at(i).at(j - 1);
//             }
//         }
//         return grid.at(m - 1).at(n - 1);
//     }
// };
