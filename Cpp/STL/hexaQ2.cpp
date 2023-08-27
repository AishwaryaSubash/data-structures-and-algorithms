#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 351;
    int m = 4950;

    if (m > n)
    {
        string s = to_string(n);
        vector<string> v;
        int flag = 0;
        do
        {
            v.push_back(s);
            if (stoi(s) > m)
            {
                cout << true;
                flag = 1;
                break;
            }
        } while (next_permutation(s.begin(), s.end()));
        if (flag == 0)
        {
            cout << false;
        }
    }

    else
        cout << false;
}