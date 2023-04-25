#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<string> ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    int ans = 0;
    stack<int> s;
    int a, b;
    string n = "";
    for (string i : ops)
    {
        // cout << i << endl;

        if (i.compare("C") == 0)
        {
            s.pop();
        }
        else if (i.compare("D") == 0)
        {
            // cout << "d " << a;
            a = s.top() * 2;
            s.push(a);
        }

        else if (i.compare("+") == 0)
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.push(a);
            s.push(a + b);
        }

        else
        {
            // n += i;
            s.push(stoi(i));
            n.clear();
        }
        // cout << "top" << s.top() << endl;
    }
    // cout << "size" << s.size() << endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout << "new" << s.top() << endl;
        ans += s.top();
        s.pop();
    }
    ans += s.top();

    cout << "ans" << ans;
}
