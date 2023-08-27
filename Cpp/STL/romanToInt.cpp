#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "LVIII";
    vector<char> v = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i != s.length() - 1)
        {
        //     if (m[s.at(i)] >= m[s.at(i + 1)])
        //     {
        // sum += m[s.at(i)].second;
        //     }
        }
    }
    cout << sum;
}