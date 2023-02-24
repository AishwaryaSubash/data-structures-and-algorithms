#include <bits/stdc++.h>
using namespace std;

void func(vector<int> v, int m)
{
    int k = 0;
    while (m != 0)
    {
        v.push_back(v.at(0));
        v.erase(v.begin());
        k++;
        m--;
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int n = 2;
    func(v, n);
}

