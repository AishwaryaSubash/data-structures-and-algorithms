#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcadbcbb";
    map<char, int> m;
    int len = 0, maxLen = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (m.find(s.at(i)) == m.end())
        {
            m[s.at(i)] = 1;
            len++;
        }
        else
        {
            // if (m[s.at(i)] >= 1)
            //     len++;
            m.clear();
            m[s.at(i)]++;
            if (len > maxLen)
            {
                maxLen = len;
                cout << "ind" << i;
                len = 0;
            }
        }
        cout << "new ";
        for (pair<char, int> p : m)
        {
            cout << p.first << " " << p.second << endl;
        }
    }

    cout << maxLen;
}