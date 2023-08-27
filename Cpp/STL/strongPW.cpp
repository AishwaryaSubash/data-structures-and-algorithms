#include <bits/stdc++.h>
using namespace std;

int main()
{
    string pw = "loveLe3tcode!";
    bool len = false, l = false, u = false, d = false, s = false, c = false;
    if (pw.length() >= 8)
    {
        len = true;
    }
    else
    {
        for (int i = 0; i < pw.length(); i++)
        {
            if (islower(pw[i]))
                l = true;
            else if (isupper(pw[i]))
                u = true;
            else if (isdigit(pw[i]))
                d = true;
            else
                s = true;
            if (i != pw.length() - 1 && pw[i] == pw[i + 1])
                break;
            else
                c = true;
        }
    }
    cout << len << l << u << d << s << c << endl;
    if (len && l && u && d && s && c)
        cout << true;
    else
        cout << false;
}