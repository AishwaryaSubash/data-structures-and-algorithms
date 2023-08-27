#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int flag = 0;
    vector<int> v = {14, 25, 71, 65, 10};
    for (int i = 0; i < v.size(); i++)
    {
        if (n < v.at(i))
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << 1;
    else
        cout << 0;
}