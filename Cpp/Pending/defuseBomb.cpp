#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> code = {5, 7, 1, 4};
    int k = 3;
    int n = code.size();
    vector<int> ans;

    for (int i = 0; i < code.size(); i++)
    {
        if (k < 0)
            code.push_back(code.at(i));
    }
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        if (k == 0)
        {
            ans.push_back(0);
        }
        else if (k < 0)
        {
        }
        else
        {
        }
    }
}