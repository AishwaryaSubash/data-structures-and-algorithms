#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> prices = {2, 4, 1};
    int profit = 0;
    int buy = prices.at(0);

    // O(N)
    for (int i = 1; i < prices.size(); i++)
    {
        if (buy > prices.at(i))
        {
            buy = prices.at(i);
        }
        else if (profit < prices.at(i) - buy)
        {
            profit = prices.at(i) - buy;
        }
    }
    cout << profit;

    // O(N^2)
    // for (int j = 0; j < prices.size(); j++)
    // {
    //     for (int i = j + 1; i < prices.size(); i++)
    //     {
    //         if (prices.at(i) - prices.at(j) > profit)
    //             profit = prices.at(i) - prices.at(j);
    //     }
    // }
}