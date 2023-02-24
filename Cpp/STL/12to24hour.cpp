#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "12:45:54PM";
    string time = s.substr(8, 2);
    int hour;
    if (time.compare("PM") == 0)
    {
        hour = stoi(s.substr(0, 2));
        if (hour == 24)
            hour = 0;
        hour += 12;
        string hr = to_string(hour);
        if (hr.length() == 1)
            hr.insert(hr.begin(), '0');
        s.erase(s.begin(), s.begin() + 2);
        s.erase(s.end() - 2, s.end());
        s.insert(s.begin(), hr[1]);
        s.insert(s.begin(), hr[0]);
    }
    if (time.compare("AM") == 0)
    {
        hour = stoi(s.substr(0, 2));
        if (hour == 12)
            hour = 0;

        string hr = to_string(hour);
        if (hr.length() == 1)
            hr.insert(hr.begin(), '0');
        s.erase(s.begin(), s.begin() + 2);
        s.erase(s.end() - 2, s.end());
        s.insert(s.begin(), hr[1]);
        s.insert(s.begin(), hr[0]);
    }
    if (s[1] == ':')
    {
        s.insert(s.begin(), '0');
    }
    cout << s;
}