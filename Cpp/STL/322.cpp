#include <bits/stdc++.h>
using namespace std;

// Coin Change
int main()
{
    vector<int> coins = {186, 419, 83, 408};
    int amount = 6249;
    sort(coins.begin(), coins.end());
    reverse(coins.begin(), coins.end());
    int count = 0, ind = 0;
    stack<int> s;
    s.push(amount);
    while (amount > 0)
    {
        int val = int(amount / coins.at(ind));
        if (val > 0)
        {
            count += val;
            amount -= val * coins.at(ind);
            s.push(amount);
        }
        ind++;
        if (ind >= coins.size())
        {
            s.pop();
        }
        cout << amount << " " << coins.at(ind) << " " << count << endl;
    }
    if (amount == 0)
        cout << count;
    else
        cout << "-1";
}