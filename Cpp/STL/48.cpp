#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    reverse(matrix.begin(), matrix.end());

    int temp = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix.at(j).at(i), matrix.at(i).at(j));
        }
    }

    // Not In-place
    // vector<vector<int>> ans;
    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     vector<int> col;
    //     for (int j = 0; j < matrix.size(); j++)
    //     {
    //         col.push_back(matrix.at(j).at(i));
    //     }
    //     ans.push_back(col);
    //     col.clear();
    // }

    for (vector<int> v : matrix)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}