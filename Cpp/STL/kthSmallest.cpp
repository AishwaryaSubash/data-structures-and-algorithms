
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s.erase(remove(s.begin(), s.end(), '}'), s.end());
    s.erase(remove(s.begin(), s.end(), '{'), s.end());
    vector<int> v;
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ',')
        {
            v.push_back(stoi(temp));
            temp = "";
            continue;
        }
        temp += s[i];
    }
    int k;
    cin >> k;
    if (!temp.empty())
        v.push_back(stoi(temp));
    sort(v.begin(), v.end());

    cout << v.at(k - 1);
}