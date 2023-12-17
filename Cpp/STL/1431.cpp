#include <bits/stdc++.h>
using namespace std;

int main()
{
    int extraCandies = 10;
    vector<int> candies = {12, 1, 12};
    int max = -99;

    for (int i : candies)
        if (max < i)
            max = i;

    vector<bool> ans;
    for (int i : candies)
        ans.push_back(i + extraCandies >= max);

    for (bool b : ans)
        cout << b << " ";
}