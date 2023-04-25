#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {7, 6, 4, 3, 1};
    int max;
    int value = 0;
    if (v.size() == 1)
        cout << value;
    for (int i = 0; i < v.size() - 1; i++)
    {
        vector<int> c(v.begin() + i + 1, v.end());
        max = *max_element(c.begin(), c.end());
        if (v.at(i) > max)
            cout << 0;
        if (max - v.at(i) > value)
            value = max - v.at(i);
    }

    cout << value;
    /*
        for (int i = 0; i < v.size() - 1; i++)
        {
            for (int j = i; j < v.size(); j++)
            {
                if (v.at(i) < v.at(j) && max < v.at(j) - v.at(i))
                {
                    max = v.at(j) - v.at(i);
                }
            }
        }
        cout << max;
    */

    // for (int i = 0; i < prices.size() - 1; i++)
    // {
    //     vector<int> c(prices.begin() + i + 1, prices.end());
    //     max = *max_element(c.begin(), c.end());

    //     value = max - prices.at(i);
    // }

    // for (int i:c) {
    //     cout<<i;
    // }
    // cout << value;
}