#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> ops = {"5", "2", "C", "D", '+'};
    int ans = 0;
    vector<int> v;
    for (char i : ops)
    {
        if (isdigit(i))
        {
            v.push_back(isdigit(i));
        }
        else
        {
            if (isalpha(i))
            {
                if (i == 'C')
                {
                    v.pop_back();
                }
                if (i == 'D')
                {
                    v.push_back(v.back() * 2);
                }
            }
            if (i == '+')
            {
                v.push_back(v.back() + v.at(v.size() - 2));
            }
        }
    }
    for (int i : v)
    {
        ans += i;
    }
    cout << ans;
}
