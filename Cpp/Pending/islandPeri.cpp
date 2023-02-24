#include <bits/stdc++.h>
using namespace std;

int main()
{
    //{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}
    vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    int peri = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.at(i).size(); j++)
        {
            if (grid.at(i).at(j) == 0)
            {
                if (i != (grid.size() - 1) && j != (grid.size() - 1) && grid.at(i + 1).at(j + 1) == 1)
                {
                    peri += 1;
                }
                if (i != (grid.size() - 1) && j != 0 && grid.at(i + 1).at(j - 1) == 1)
                {
                    peri += 1;
                }
                if (i != 0 && j != (grid.size() - 1) && grid.at(i - 1).at(j + 1) == 1)
                {
                    peri += 1;
                }
                if (i != 0 && j != 0 && grid.at(i - 1).at(j - 1) == 1)
                {
                    peri += 1;
                }
            }
            if (grid.at(i).at(j) == 1)
            {
                // corners and edges
                if (i == 0 || i == grid.size() - 1)
                {
                    peri += 1;
                }
                if (j == 0 || j == grid.at(i).size() - 1)
                {
                    peri += 1;
                }
            }
            cout << i << " " << j << " " << peri << endl;
        }
    }
    cout << peri+2;
}
