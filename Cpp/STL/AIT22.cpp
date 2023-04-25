#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<vector<int>> mat;

    for (int i = 0; i < m; i++)
    {
        vector<int> c;
        for (int j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            c.push_back(k);
        }
        mat.push_back(c);
    }
    vector<vector<int>> tran(n, vector<int>(m));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tran.at(j).at(i) = mat.at(i).at(j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << tran.at(i).at(j) << " ";
        }
        cout << endl;
    }
}