#include <bits/stdc++.h>
using namespace std;

int main()
{
    string word1 = "abccccccccccccccc", word2 = "pqrstuvw";
    int length = word1.length() < word2.length() ? word1.length() : word2.length();

    string ans = "";
    for (int i = 0; i < length; i++)
    {
        ans.push_back(word1.at(i));
        ans.push_back(word2.at(i));
        if (i == length - 1)
        {
            if (length != word2.length())
                ans += word2.substr(i + 1);
            if (length != word1.length())
                ans += word1.substr(i + 1);
        }
    }
    cout << ans;
}