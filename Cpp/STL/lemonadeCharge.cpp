#include <bits/stdc++.h>
using namespace std;

// If bills are divisible

int main()
{
    vector<int> bills = {5, 5, 20, 5, 5, 10, 5, 10, 5, 20};
    int sum = 0;
    int change = 0;
    for (int i = 0; i < bills.size(); i++)
    {
        if (bills.at(i) == 5)
            sum += 5;
        if (bills.at(i) == 10)
        {
            sum += 5;
            change += 5;
        }
        if (bills.at(i) == 20)
        {
            sum += 5;
            change += 15;
        }
        if (sum < change)
            return false;
        else
            sum -= change;
    }
    if (sum >= change)
    {
        return true;
    }
}
