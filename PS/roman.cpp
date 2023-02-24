// # Algorithm to convert Roman Numerals to Integer Number:

// # Split the Roman Numeral string into Roman Symbols (character).
// # Convert each symbol of Roman Numerals into the value it represents.
// # Take symbol one by one from starting from index 0:
// #   If current value of symbol is greater than or equal to the value of next symbol, then add this value to the running total.
// #   Else subtract this value by adding the value of next symbol to the running total.

#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     string s;
//     getline(cin, s);
//     map<string, int> roman = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}};
//     return 0;
// }

int main()
{
    string s;
    getline(cin, s);
    int cnt = 0;
    map<char, int> roman = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}};
    for (int i = 0; i < s.length(); i++)
    {

        if (roman[s[i]] >= roman[s[i] + 1])
        {
            cnt += roman[s[i + 1]];
        }
        else
        {
            cnt -= roman[s[i]];
        }
    }
    return 0;
}

//  VIII