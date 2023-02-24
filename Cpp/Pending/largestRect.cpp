#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    vector<int> v = {3, 2, 3};
    int i = 0;
    int j = v.size() - 1;
    int x = 0;
    long maxi = -99;
    while (i < j)
    {
        cout << v.at(i) << " " << v.at(j) << " " << maxi << endl;
        x = min(v.at(i), v.at(j));
        if ((j - i + 1) * x > maxi)
        {
            maxi = (j - i + 1) * x;
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