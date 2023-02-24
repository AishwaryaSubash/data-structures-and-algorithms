#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int i = 0;
    int j = v.size() - 1;
    int x = 0;
    int maxi = -99;
    while (i < j)
    {
        x = min(v.at(i), v.at(j));
        if ((j - i) * x > maxi)
        {
            maxi = (j - i) * x;
        }
        if (v.at(i) < v.at(j))
        {
            i++;
        }
        else if (v.at(i) > v.at(j))
        {
            j--;
        }
        else
        {
            i++;
            j--;
        }
    }
    cout << maxi;
}