#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* cout << "Cipher" << endl;
     string pl;
     cout << "plaintext ";
     getline(cin, pl);
     transform(pl.begin(), pl.end(), pl.begin(), ::toupper);

     int k;
     cout << "key ";
     cin >> k;

     string newpl = "";
     for (int i = 0; i < pl.length(); i++)
         if (isalpha(pl[i]))
             newpl += pl[i];

     int l = newpl.length();
     bool dir_down = false;
     int row = 0, col = 0;
     vector<vector<char>> v(k, vector<char>(l, ' '));

     int x = 0;
     for (int i = 0; i < l; i++)
     {
         if (row == 0 || row == k - 1)
             dir_down = !dir_down;
         v.at(row).at(col++) = newpl[x++];
         dir_down ? row++ : row--;
     }

     string ct = "";
     for (int i = 0; i < k; i++)
         for (int j = 0; j < l; j++)
             if (isalpha(v.at(i).at(j)))
                 ct += v.at(i).at(j);

     cout << "cipher " << ct << endl;
 */
    /*
        cout << "Decipher" << endl;

        string cipher;
        cout << "cipher ";
        getline(cin, cipher);

        int k;
        cout << "key ";
        cin >> k;

        string ct = "";
        for (int i = 0; i < cipher.length(); i++)
        {
            if (isalpha(cipher[i]))
                ct += cipher[i];
        }

        int l = ct.length();
        bool dir_down = false;
        int row = 0, col = 0;
        vector<vector<char>> v(k, vector<char>(l, ' '));

        for (int i = 0; i < l; i++)
        {
            if (row == 0 || row == k - 1)
                dir_down = !dir_down;
            v.at(row).at(col++) = '-';
            dir_down ? row++ : row--;
        }

        string pl = "";
        int x = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < l; j++)
            {
                if (v.at(i).at(j) == '-')
                    v.at(i).at(j) = ct[x++];
            }
        }

        string c = "";
        row = 0, col = 0;
        dir_down = false;
        for (int i = 0; i < l; i++)
        {
            if (row == 0 or row == k - 1)
                dir_down = !dir_down;
            c += v.at(row).at(col++);
            dir_down ? row++ : row--;
        }

        cout << "cipher " << c;
        */

    string pl;
    cout << "plaintext ";
    getline(cin, pl);

    int k;
    cout << "key ";
    cin >> k;

    string newpl = "";
    for (int i = 0; i < pl.length(); i++)
        if (isalpha(pl[i]))
            newpl += pl[i];

    int l = newpl.length();
    vector<vector<char>> v(k, vector<char>(l, ' '));

    bool dir_down = false;
    int row = 0, col = 0;
    for (int i = 0; i < l; i++)
    {
        if (row == 0 || row == k - 1)
            dir_down = !dir_down;
        v.at(row).at(col++) = newpl[i];
        dir_down ? row++ : row--;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cout << v.at(i).at(j);
        }
        cout << endl;
    }
}