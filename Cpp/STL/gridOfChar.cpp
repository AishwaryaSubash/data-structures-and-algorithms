#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> v = {"abc", "lmp", "qrt"};

    for (int i = 0; i < v.size(); i++)
    {
        sort(v.at(i).begin(), v.at(i).end());
    }
    int len = (v.at(0).length() == v.size()) ? 0 : 1;
    for (int j = 0; j < v.at(0).size(); j++)
    {
        for (int i = 1; i < v.at(j).size() + len; i++)
        {
            if (v.at(i).at(j) - v.at(i - 1).at(j) < 0)
            {
                cout << "NO";
                return 0;
            }
            cout << v.at(i).at(j) << v.at(i - 1).at(j) << endl;
        }
    }
    cout << "YES";
}