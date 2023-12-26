#include <bits/stdc++.h>
using namespace std;

int main()
{
    int choice;
    do
    {
        cout << "\n1.Cipher\n2.Decipher\n3.Fence pattern\n4.Exit\nEnter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int k;
            string pl;
            string newPl;

            cout << "\nEnter plain text: ";
            cin.ignore();
            getline(cin, pl);

            cout << "Enter key value: ";
            cin >> k;
            transform(pl.begin(), pl.end(), pl.begin(), ::toupper);

            for (int i = 0; i < pl.length(); i++)
            {
                if (isalpha(pl[i]))
                {
                    newPl += pl[i];
                }
            }

            int l = newPl.length();
            vector<vector<char>> vec(k, vector<char>(l, ' '));

            bool dir_down = false;
            int row = 0, col = 0;

            for (int i = 0; i < l; i++)
            {
                if (row == 0 || row == k - 1)
                    dir_down = !dir_down;
                vec.at(row).at(col++) = newPl[i];
                dir_down ? row++ : row--;
            }

            string res = "";
            for (int i = 0; i < k; i++)
                for (int j = 0; j < l; j++)
                    if (isalpha(vec.at(i).at(j)))
                        res += vec.at(i).at(j);

            cout << "Cipher text: " << res << endl;
            break;
        }

        case 2: // Fence in decipher
        {
            string dec_res = "";
            int k;
            string pl;
            string newPl;

            cout << "\nEnter cipher text: ";
            cin.ignore();
            getline(cin, pl);

            cout << "Enter key:";
            cin >> k;
            transform(pl.begin(), pl.end(), pl.begin(), ::toupper);

            for (int i = 0; i < pl.length(); i++)
                if (isalpha(pl[i]))
                    newPl += pl[i];

            int l = newPl.length();
            int c = 0;

            vector<vector<char>> vec(k, vector<char>(l, ' '));
            bool dir_down = false;
            int row = 0, col = 0;

            for (int i = 0; i < l; i++)
            {
                if (row == 0 || row == k - 1)
                    dir_down = !dir_down;
                vec.at(row).at(col++) = '-';
                dir_down ? row++ : row--;
            }

            int x = 0;
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    if (vec.at(i).at(j) == '-')
                    {
                        vec.at(i).at(j) = newPl[x++];
                    }
                }
            }

            row = 0;
            col = 0;
            dir_down = false;
            for (int i = 0; i < l; i++)
            {
                if (row == 0 || row == k - 1)
                    dir_down = !dir_down;
                dec_res += vec.at(row).at(col++);
                dir_down ? row++ : row--;
            }
            
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < l; j++)
                    cout << vec.at(i).at(j);
                cout << endl;
            }
            cout << "decr: " << dec_res << endl;
            break;
        }
        case 3: // Fence in ciphering
        {
            string txt;
            string newtxt;
            char a[100][100];
            bool dir_d = false;
            cout << "\nEnter plain text: ";
            cin.ignore();
            getline(cin, txt);
            int keyy;
            cout << "Enter key: ";
            cin >> keyy;
            transform(txt.begin(), txt.end(), txt.begin(), ::toupper);
            for (int i = 0; i < txt.length(); i++)
            {
                if (isalpha(txt[i]))
                    newtxt += txt[i];
            }
            int l = newtxt.length();
            vector<vector<char>> vec(keyy, vector<char>(l, ' '));
            int row = 0, col = 0;
            for (int i = 0; i < l; i++)
            {
                if (row == 0 || row == keyy - 1)
                    dir_d = !dir_d;
                vec.at(row).at(col++) = newtxt[i];
                dir_d ? row++ : row--;
            }
            for (int i = 0; i < keyy; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    cout << vec.at(i).at(j);
                }
                cout << endl;
            }
            break;
        }
        default:
            break;
        }
    } while (choice != 4);
}
