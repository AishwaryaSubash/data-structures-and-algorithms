#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> prices = {2, 4, 1};
    int min = 9999, ind = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices.at(i) < min)
        {
            min = prices.at(i);
            ind = i;
        }
    }

    int profit = 0;
    for (int i = ind; i < prices.size(); i++)
    {
        if (prices.at(i) - min > profit)
            profit = prices.at(i) - min;
    }
    cout << profit;
}