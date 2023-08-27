#include <bits/stdc++.h>
using namespace std;

int main()
{
    int target;
    int n;
    cout << "n: ";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v.at(i);
    }
    cout << "t: ";
    cin >> target;

    vector<vector<int>> vec;
    for (int i = 0; i < n; i++)
    {
        int curr = v.at(i + 1);
        for (int j = i; j < n; j++)
        {
            
        }
    }


}