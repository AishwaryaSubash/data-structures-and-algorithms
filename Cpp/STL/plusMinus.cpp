#include <bits/stdc++.h>
using namespace std;

int main()
{
    float n = 6;
    vector<int> v = {-4, 3, -9, 0, 4, 1};
    float pc = 0, nc = 0, zc = 0;
    vector<float> ans;
    for (int i = 0; i < n; i++)
    {
        if (v.at(i) < 0)
            nc++;
        if (v.at(i) > 0)
            pc++;
        if (v.at(i) == 0)
            zc++;
    }
    ans.push_back(pc / n);
    ans.push_back(nc / n);
    ans.push_back(zc / n);
    for (float i : ans)
    {
        printf("%.5f\n", i);
    }
}