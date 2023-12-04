#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int num;
    cin >> num;
    string s = to_string(num);
    map<int, char> mp;
    vector<char> vow = {'a', 'e', 'i', 'o', 'u'};
    vector<char> con;
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (find(vow.begin(), vow.end(), i) == vow.end())
            con.push_back(i);
    }
    string ans = "";
    for (char i : s)
    {
        string j = "";
        j += i;
        // cout << stoi(j) << endl;
        int k = stoi(j);
        if (isPrime(k))
        {
            if (mp.find(k) == mp.end())
            {
                mp[k] = vow.front();
                vow.erase(vow.begin());
            }
        }
        else
        {
            if (mp.find(k) == mp.end())
            {
                mp[k] = con.front();
                con.erase(con.begin());
            }
        }
        ans += mp[k];
    }
    cout << ans << endl;
}