#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> v = {{0, 0, 1}, {1, 0, 1}, {1, 0, 0}};
    vector<vector<int>> w;
    vector<int> x;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = v.size() - 1; j >= 0; j--)
        {
            if (v.at(i).at(j) == 1)
            {
                x.push_back(0);
            }
            else
            {
                x.push_back(1);
            }
        }
        w.push_back(x);
        x.clear();
    }

    for (int i = 0; i < w.size(); i++)
    {
        for (int j = 0; j < w[i].size(); j++)
        {
            cout << w[i][j];
        }
        cout << endl;
    }
}