#include <bits/stdc++.h>
using namespace std;

int main()
{
    int choice;
    do
    {
        cout << "\n1.Cipher\n2.Decipher\n3.Exit\nEnter Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int k;
            string pl;
            string newPl;
            string res;
            cout << "Enter plain text: ";
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
            int c = 0;
            char arr[100][100];

            bool dir_down = false;
            int row = 0, col = 0;

            // since karthi is incapable he used GFG tq
            for (int i = 0; i < l; i++)
            {

                if (row == 0 || row == k - 1)
                    dir_down = !dir_down;

                arr[row][col++] = newPl[i];

                dir_down ? row++ : row--;
            }
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    if (isalpha(arr[i][j]))
                    {
                        res.push_back(arr[i][j]);
                    }
                }
            }
            cout << "Cipher text: " << res << endl;
            break;
        }
        case 2:
        {
            string dec_res;
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
            {
                if (isalpha(pl[i]))
                {
                    newPl += pl[i];
                }
            }
            int l = newPl.length();
            cout << "\n"
                 << l << endl;
            int c = 0;
            char arr[100][100];
            bool dir_down = false;
            int row = 0, col = 0;
            for (int i = 0; i < l; i++)
            {
                if (row == 0 || row == k - 1)
                    dir_down = !dir_down;
                arr[row][col++] = '-';
                dir_down ? row++ : row--;
            }

            int x = 0;
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    if (arr[i][j] == '-')
                    {
                        arr[i][j] = newPl[x++];
                    }
                }
            }
            // Decryption
            dir_down = true;
            int num = 0;
            int a = 0;
            int b = 0;
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    dec_res += arr[a][b];
                    if (dir_down == true)
                    {
                        a++;
                    }
                    if (dir_down == false)
                    {
                        a--;
                    }
                    b++;
                    num++;
                    if (num == k - 1)
                    {
                        dir_down = !dir_down;
                        num = 0;
                    }
                }
                cout << endl;
            }
            // GSGSEKFREKEOE

            row = col = 0;

            cout << "decr: " << dec_res << endl;
            break;
        }

        default:
            break;
        }
    } while (choice != 3);
}
