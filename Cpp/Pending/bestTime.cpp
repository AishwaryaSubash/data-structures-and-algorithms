#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    for (int i = 0; i < prices.size() - 1; i++)
    {
        vector<int> c(prices.begin() + i + 1, prices.end());
        int max = *max_element(c.begin(), c.end());
    }
}