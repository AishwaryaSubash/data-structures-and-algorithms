#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int sum = 0;
    int current;
    int index = 0;
    while (current != cost.at(cost.size() - 1) || current != cost.at(cost.size() - 2))
    {
        if (index != cost.size() - 1)
        {

            current = min(cost.at(index), cost.at(index + 1));
            sum += current;
        }
        cout << sum;
    }
    return sum;
}

int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << minCostClimbingStairs(cost);
}