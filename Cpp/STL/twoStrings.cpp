#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "abvgchsshvdfygefbjbhgvcs";
    string s2 = "abvgchss";
    map<char, int> m;

    // O(n)
    for (int i = 0; i < s2.length(); i++)
    {
        m[s2[i]]++;
    }
    for (int i = 0; i < s1.length(); i++)
    {
        if (m.find(s1[i]) != m.end())
        {
            s1.erase(i, 1);
            i--;
        }
    }

    // O(n^2)
    // for (int i = 0; i < s1.length(); i++)
    // {
    //     for (int j = 0; j < s2.length(); j++)
    //     {
    //         if (s1[i] == s2[j])
    //         {
    //             s1.erase(i, 1);
    //             i--;
    //         }
    //     }
    // }
    cout << s1;
}