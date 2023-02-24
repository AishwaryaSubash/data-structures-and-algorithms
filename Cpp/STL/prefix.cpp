#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> strs = {"hell", "hello"};
    vector<string> copy(strs);
    string first = strs.at(0);
    copy.erase(copy.begin());
    string ans = "";
    for (string s : copy)
    {
        int ind = 0;
        for (char i : s)
        {
            if (first[ind] == i)
            {
                ans += i;
            }
            else
            {
                break;
            }
            ind++;
        }
        first = ans;
        ans = "";
    }
    cout << first << endl;
}