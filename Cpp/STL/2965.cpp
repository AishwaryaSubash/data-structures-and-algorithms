#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
{
    vector<int> ans;
    map<int, int> m;
    int n = grid.size();
    vector<int> nums;

    for (vector<int> v : grid)
    {
        for (int i : v)
            m[i]++;
    }
    int a, b;
    for (pair<int, int> p : m)
    {
        if (p.second == 2)
            a = p.first;
        nums.push_back(p.first);
    }
    sort(nums.begin(), nums.end());

    ans.push_back(a);
    ans.push_back(b);
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    vector<int> ans = findMissingAndRepeatedValues(grid);
    for (int i : ans)
        cout << i << " ";
}