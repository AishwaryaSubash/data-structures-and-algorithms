#include <bits/stdc++.h>
using namespace std;
// 347. Top K Frequent Elements

int main()
{
    // O(n) - all passed
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    map<int, int> m;
    for (int i : nums)
        m[i]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for (auto p : m)
    {
        minHeap.push(make_pair(p.second, p.first));
        if (k < minHeap.size())
            minHeap.pop();
    }
    vector<int> ans;
    while (!minHeap.empty())
    {
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }

    for (int j : ans)
        cout << j << " ";

    // O(n) - some didnt pass
    // vector<int> ans;
    // map<int, int> m;
    // for (int i : nums)
    //     m[i]++;

    // vector<int> freq;
    // for (auto p : m)
    // {
    //     freq.push_back(p.second);
    // }
    // sort(freq.begin(), freq.end());
    // int max = freq.back();
    // freq.pop_back();
    // int max2 = freq.back();
    // for (auto p : m)
    // {
    //     if (p.second == max || p.second == max2)
    //     {
    //         ans.push_back(p.first);
    //     }
    // }
    // for (int i : ans)
    //     cout << i << endl;
}