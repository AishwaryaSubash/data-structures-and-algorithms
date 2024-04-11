#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    vector<int> row(matrix.size());
    vector<int> col(matrix.at(0).size());

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.at(i).size(); j++)
        {
            if (matrix.at(i).at(j) == 0)
            {
                row.at(i) = 1;
                col.at(j) = 1;
            }
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.at(i).size(); j++)
        {
            if (row.at(i) == 1 || col.at(j) == 1)
            {
                matrix.at(i).at(j) = 0;
            }
        }
    }

    for (vector<int> v : matrix)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}