#include <bits/stdc++.h>
using namespace std;

int special(int num)
{
    // int num;
    // cin >> num;
    vector<int> factors;
    for (int i = 1; i <= (num / 2); i++)
    {
        if (num % i == 0)
        {
            factors.push_back(i);
        }
    }
    int sum = 0;
    for (int n : factors)
    {
        sum += n;
    }
    if (sum == num)
    {
        return num;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int l = 6, r = 10;
    int ans;
    int sum = 0;
    for (int i = l; i < r; i++)
    {
        ans = special(i);
        if (ans != -1)
        {
            sum += ans;
        }
    }
    cout << sum;
}