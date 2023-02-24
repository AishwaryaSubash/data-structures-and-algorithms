#include <bits/stdc++.h>
using namespace std;

int main()
{
    int rows = 3;
    string s = "PAYPALISHIRING";
    string ans = "";
    int x = rows - 2;
    int next = x + rows;
    vector<vector<int>> v;
    // cout << next;
    int a = 0;
    int b = next;
    for (int i = 0; i < rows; i++)
    {
        v.push_back({a, b});
        a += 2;
        b -= 2;
    }
    bool tog = true;
    for (int i = 0; i < rows; i++)
    {
        //{0,4}{2,2}{4,0}
        for (int j = 0; j < s.length();)
        {
            if (v.at(i).at(0) != 0)
            {
                j += v.at(i).at(0);
                ans += s[j];
            }

            j += v.at(i).at(1);
            ans += s[j];
        }

        // for (int j = 0; j < s.length();)
        // {
        //     if (tog)
        //     {
        //         j += v.at(i).at(0);
        //         ans += s[j];
        //     }
        //     else
        //     {
        //         j += v.at(i).at(1);
        //         ans += s[j];
        //     }
        //     tog = !tog;
        // }
    }
    cout << ans;

    // PPAAHHNNPYAIHRNPPAAHHNN
    // PAAHHNNPYAIHRNPPAAHHNN
}

// 3 4   1 PAHNAPLSIIGYIR
// 4 6   2 PINALSIGYAHRPI
// 5 8   3
// 6 10  4
// 7 12  5
// 8 14    6
// PAYPALISHIRING
// phasiyirpligan

// p
//     a
//         y
//             p
//                 a
//                     l
//                         i
//                             s
//                                 h

// p     h
// a   s i
// y  i  r
// p l   i g
// a     n

// p      r
// a    i i
// y   h  n
// p  s   g
// a i
// l
