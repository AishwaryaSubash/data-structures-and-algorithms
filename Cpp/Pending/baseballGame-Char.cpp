#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> ops = {'5', '2', 'C', 'D', '+'};
    int ans = 0;
    stack<int> s;
    int a, b;
    string n = "";
    for (char i : ops)
    {
        // cout << i << endl;

        if (isdigit(i))
        {
            n += i;
            s.push(stoi(n));
            n.clear();
        }
        else
        {
            if (!s.empty())
            {
                if (isalpha(i))
                {
                    if (i == 'C')
                    {
                        s.pop();
                    }
                    if (i == 'D')
                    {
                        a = s.top() * 2;
                        s.push(a);
                    }
                }
                if (i == '+')
                {
                    a = s.top();
                    s.pop();
                    b = s.top();
                    s.push(a);
                    s.push(a + b);
                }
            }
        }
        // cout << "top" << s.top() << endl;
    }
    // cout << "size" << s.size() << endl;
    for (int i = 0; i < s.size(); i++)
    {
        // cout << s.top() << endl;
        ans += s.top();
        s.pop();
    }
    ans += s.top();
    cout << ans;
}
