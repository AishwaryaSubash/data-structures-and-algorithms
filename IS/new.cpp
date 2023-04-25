#include <bits/stdc++.h>
using namespace std;
int main()
{
    string pl, newPl, dec_res = "";
    int k, c = 0, row = 0, col = 0, x = 0;
    bool dir_down = false;
    cout << "\nEnter cipher text: ";
    getline(cin, pl);
    cout << "Enter key:";
    cin >> k;
    transform(pl.begin(), pl.end(), pl.begin(), ::toupper);
    for (int i = 0; i < pl.length(); i++)
        if (isalpha(pl[i]))
            newPl += pl[i];
    vector<vector<char>> vec(k, vector<char>(newPl.length(), ' '));
    for (int i = 0; i < newPl.length(); i++)
    {
        if (row == 0 || row == k - 1)
            dir_down = !dir_down;
        vec.at(row).at(col++) = '-';
        dir_down ? row++ : row--;
    }
    for (int i = 0; i < k; i++)
        for (int j = 0; j < newPl.length(); j++)
            if (vec.at(i).at(j) == '-')
                vec.at(i).at(j) = newPl[x++];
    dir_down = false;
    row = 0;
    col = 0;
    for (int i = 0; i < newPl.length(); i++)
    {
        if (row == 0 || row == k - 1)
            dir_down = !dir_down;
        dec_res += vec.at(row).at(col++);
        dir_down ? row++ : row--;
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < newPl.length(); j++)
            cout << vec.at(i).at(j);
        cout << endl;
    }
    cout << "decr: " << dec_res << endl;
    return 0;
}