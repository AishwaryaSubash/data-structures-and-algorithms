#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "1 2 3 4 5 6 1";
    vector<char> nums;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            nums.push_back(s[i]);
        }
    }
    for (char n : nums)
    {
        cout << n << " ";
    }
    unordered_map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            m[s[i]] += 1;
        }
    }
    cout << endl;
    int flag = 1;
    for (pair<char, int> elem : m)
    {
        if (elem.second > 1)
        {
            cout << elem.first << " ";
            flag = 0;
        }
    }
    if (flag == 1)
    {
        cout << "No duplicates";
    }
    cout << endl;
}