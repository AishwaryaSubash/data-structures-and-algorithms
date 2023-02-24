#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 0, 0, 0, 3, 4, 0};
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            v.erase(v.begin() + i);
            i--;
            count++;
        }
    }

    for (int i = 0; i < count; i++)
    {
        v.push_back(0);
    }

    for (int i = 0; i < v.size(); i++)
    {

        cout << v[i];
    }
}
