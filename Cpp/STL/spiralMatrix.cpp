#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans;
    int len = v.size() * v.at(0).size();
    int j = 0, i = 0;
    for (int k = 0; k < len; k++)
    {
        while (j != v.size())
        {
            ans.push_back(v.at(i).at(j++));
            cout << i << " " << j << endl;
        }
        j--;
        i++;
        while (i != v.size())
        {
            ans.push_back(v.at(i++).at(j));
            cout << i << " " << j << endl;
        }
        i--;
        j--;
        while (j != 0)
        {
            ans.push_back(v.at(i).at(j--));
            cout << i << " " << j << endl;
        }
        break;
    }
    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << endl;
}