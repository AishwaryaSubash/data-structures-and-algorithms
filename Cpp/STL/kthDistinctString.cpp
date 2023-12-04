#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> arr = {"a", "b", "a"};
    int k = 3;
    vector<string> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count(arr.begin(), arr.end(), arr.at(i)) == 1)
            ans.push_back(arr.at(i));
    }
    if (k <= ans.size())
        cout << ans.at(k - 1);
    else
        cout << "";
}