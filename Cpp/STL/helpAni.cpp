#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {3, 4, 6, 6, 3};
    int ans = 0;

    set<int> s;
    while (s.size() != 1)
    {
        s = set<int>(v.begin(), v.end());
        int max = *max_element(v.begin(), v.end());
        int c = count(v.begin(), v.end(), max);
        int flag = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v.at(i) == max && c > 1 && flag == 0)
            {
                v.at(i)++;
                flag = 1;
            }
            else
            {
                if (v.at(i) != max)
                    v.at(i)++;
            }
        }
        for (int i = 0; i < v.size(); i++)
            cout << v.at(i) << " ";
        cout << endl;
        ans++;
    }
    cout << endl
         << ans;
}