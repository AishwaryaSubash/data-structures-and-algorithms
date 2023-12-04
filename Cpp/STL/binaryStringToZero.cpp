#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "100101111";
    int count = 0;

    while (s != "0" || s.back() != '0')
    {
        if (s.back() == '1')
        {
            s.back() = '0';
            count++;
        }
        else if (s.back() == '0')
        {
            s.pop_back();
            count++;
        }
        cout << s << endl;
    }
    cout << count;
}