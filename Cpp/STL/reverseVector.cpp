#include <bits/stdc++.h>
using namespace std;

vector<int> reverseArray(vector<int> a)
{
    vector<int> b;
    for (int i=a.size()-1 ; i>=0 ; i--)
    {
        int val = a.at(i);
        b.push_back(val);
    }
    return b;
}

int main()
{
    vector<int> strs = {1, 4, 3, 2};
    vector<int> hi = reverseArray(strs);

    for (int i = 0; i < strs.size(); i++)
    {
        cout << hi.at(i) << " ";
    }
}