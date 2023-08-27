#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> v;
    int x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    cin >> x;

    float greater = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (x < v.at(i))
            greater++;
    }
    if (greater != 0)
        cout << greater / n;
    else
        cout << 0;
}