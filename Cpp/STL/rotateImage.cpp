#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //[[7,4,1],[8,5,2],[9,6,3]]
    vector<vector<int>> ans;

    vector<int> v;
    for (int i = 0; i < matrix.size(); i++)
    {

        for (int j = matrix.at(i).size() - 1; j >= 0; j--)
        {
            v.push_back(matrix.at(j).at(i));
        }
        ans.push_back(v);
        v.clear();
    }
    matrix.clear();
    for (vector<int> a : ans)
    {
        for (int i : a)
        {
            v.push_back(i);
        }
        matrix.push_back(v);
        v.clear();
    }
}

// for (int i = matrix.size() - 1; i >= 0; i--)
// {
//     for (int j = matrix.at(i).size() - 1; j >= 0; j--)
//     {
//         cout << matrix.at(j).at(i) << " ";
//     }
//     cout << endl;
// }
// cout << endl;