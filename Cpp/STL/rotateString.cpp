#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "abcd";
    string s2 = "cdabe";
    int flag = 0;
    vector<char> v(s1.begin(), s1.end());
    for (int i = 0; i < s1.length(); i++)
    {

        rotate(v.begin(), v.begin() + i, v.end());
        string s3(v.begin(), v.end());
        if (s3.compare(s2) == 0)
        {
            // for (char c : v)
            // {
            //     cout << c;
            // }
            cout << true;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        cout << false;
    }
}