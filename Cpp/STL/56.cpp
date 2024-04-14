#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> mergeIntervals()
// {
// }

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<int> newpair;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals.at(i - 1).at(1) >= intervals.at(i).at(0))
        {
            newpair.push_back(intervals.at(i - 1).at(0));
            newpair.push_back(intervals.at(i).at(1));
            intervals.insert(intervals.begin() + i, newpair);
        }
    }

    for (vector<int> v : intervals)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}