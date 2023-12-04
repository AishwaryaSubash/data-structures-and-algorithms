#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v.at(i);
    }
    vector<vector<int>> ans;
    int next = 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> vec;
        int start = i;
        vec.push_back(start);
        while (true)
        {
            next = v.at(next - 1);
            count++;
            if (next == start || next == next)
            {
                cout << "No";
                break;
            }
            vec.push_back(next);
        }
        next = start;
        ans.push_back(vec);
    }
    // for (vector<int> w : ans)
    // {
    //     for (int i : w)
    //     {
    //         cout << i;
    //     }
    //     cout << endl;
    // }
}