#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    vector<string> f = {"home", "myfirst", "downloads", "myfirst", "myfirst"};
    map<string, int> m;
    vector<string> ans;
    int k = 1;
    for (int i = 0; i < f.size(); i++)
    {
        if (m.find(f.at(i)) != m.end())
        {
            ans.push_back(f.at(i) + to_string(k));
            k++;
        }
        else
            ans.push_back(f.at(i));
        m[f.at(i)]++;
    }
    for (string s : ans)
    {
        cout << s << endl;
    }
}