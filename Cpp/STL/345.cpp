#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main()
{
    string s = "hello";
    vector<int> ind;
    vector<char> vowels;
    for (int i = 0; i < s.length(); i++)
    {
        if (isVowel(s.at(i)))
        {
            vowels.push_back(s.at(i));
            ind.push_back(i);
        }
    }
    reverse(vowels.begin(), vowels.end());

    // for (char i : vowels)
    //     cout << i << " ";

    for (int i : ind)
    {
        s[i] = vowels.at(i);
        // s.replace(i, 1, to_string(vowels.at(i)));
    }

    // s.erase(s.begin() + 1);
    // s.at(i) = vowels.at(i);
    cout << s;
}