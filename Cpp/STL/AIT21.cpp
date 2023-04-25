#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<vector<int>> mat;
    cin >> n;
    for (int i = 0; i < n; i++)
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
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                sum1 += mat.at(i).at(j);
            if (i + j == n - 1)
                sum2 += mat.at(i).at(j);
            //cout << mat.at(i).at(j) << " ";
        }
        //cout << endl;
    }
    if (sum1 < sum2)
        cout << sum2 - sum1;
    else
        cout << sum1 - sum2;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << mat.at(i).at(j);
    //     }
    // }
}