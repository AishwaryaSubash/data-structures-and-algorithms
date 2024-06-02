#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    ans.push_back(intervals.at(0));
    for (int i = 0; i < intervals.size(); i++)
    {
        if (ans.empty() || intervals.at(i).at(0) > ans.back().at(1))
        {
            ans.push_back(intervals.at(i));
        }
        else
        {
            ans.back().at(1) = max(ans.back().at(1), intervals.at(i).at(1));
        }
    }

    for (vector<int> v : ans)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> newpair = mergeIntervals(intervals);

    for (vector<int> v : newpair)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}