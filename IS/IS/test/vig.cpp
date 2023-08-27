#include <bits/stdc++.h>
using namespace std;

int main()
{
    // vector<vector<char>> matrix;
    // vector<char> alpha;

    // for (char c = 'A'; c <= 'Z'; c++)
    //     alpha.push_back(c);

    // for (int i = 0; i < 26; i++)
    // {
    //     matrix.push_back(alpha);
    //     char top = alpha.front();
    //     alpha.erase(alpha.begin());
    //     alpha.push_back(top);
    // }

    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     for (int j = 0; j < matrix.at(i).size(); j++)
    //         cout << matrix.at(i).at(j) << " ";
    //     cout << endl;
    // }

    string pl;
    cout << "plain ";
    getline(cin, pl);

    string kw;
    cout << "keyword ";
    getline(cin, kw);
    transform(pl.begin(), pl.end(), pl.begin(), ::toupper);
    transform(kw.begin(), kw.end(), kw.begin(), ::toupper);
    string newpl = "", newkw = "";
    for (int i = 0; i < pl.length(); i++)
        if (isalpha(pl[i]))
            newpl += pl[i];

    for (int i = 0; i < kw.length(); i++)
        if (isalpha(kw[i]))
            newkw += kw[i];

    while (newkw.length() < newpl.length())
        newkw += newkw;
    newkw = newkw.substr(0, newpl.length());

    string ct = "";
    for (int i = 0; i < newpl.length(); i++)
    {
        if (int(newpl[i] + newkw[i]) < (91 + 65))
            ct += char(newpl[i] + newkw[i] - 65);
        else
            ct += char(newpl[i] + newkw[i] - 91);
    }
    cout << ct << endl;
}