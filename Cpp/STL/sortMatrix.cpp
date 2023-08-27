#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> v = {{14, 25, 71, 65, 10}, {47, 85, 41, 25, 36}, {99, 52, 74, 31, 13}, {52, 56, 74, 63, 65}};
    vector<int> a;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.at(i).size(); j++)
        {
            a.push_back(v.at(i).at(j));
        }
    }
    sort(a.begin(), a.end());
    int k = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.at(i).size(); j++)
        {
            cout << a.at(k) << " ";
            k++;
        }
        cout << endl;
    }
}