#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int ch;
    do
    {
        cout << " 1.Cipher \n 2.Decipher \n 3.All possible k values \n 4.Exit ";
        cout << "\n Enter option : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter plain text : ";
            cin.ignore();

            // For multiline input
            getline(cin, str);
            int k;
            cout << "Enter k : ";
            cin >> k;

            // 26 alpha
            k %= 25;
            cout << "Cipher text : ";
            transform(str.begin(), str.end(), str.begin(), ::toupper);

            // A 65, Z 90, a 97,
            for (int i = 0; i < str.length(); i++)
            {
                if (isalpha(str[i]))
                {
                    if (int(str[i]) + k > 90)
                    {
                        cout << char(str[i] + k - 26);
                    }
                    else
                    {
                        cout << char(str[i] + k);
                    }
                }
                else
                {
                    cout << str[i];
                }
            }
            break;
        }
        case 2:
        {
            cout << "Enter cipher text : ";
            cin.ignore();
            getline(cin, str);
            int k1;
            cout << "Enter k : ";
            cin >> k1;
            k1 %= 25;
            cout << "Plain text : ";
            transform(str.begin(), str.end(), str.begin(),
                      ::toupper);
            for (int i = 0; i < str.length(); i++)
            {
                if (isalpha(str[i]))
                {
                    if (int(str[i]) - k1 < 65)
                    {
                        cout << char(str[i] - k1 + 26);
                    }
                    else
                    {
                        cout << char(str[i] - k1);
                    }
                }
                else
                {
                    cout << str[i];
                }
            }
            break;
        }
        case 3:
            cout << "Enter cipher text : ";
            cin.ignore();
            getline(cin, str);
            transform(str.begin(), str.end(), str.begin(),
                      ::toupper);
            for (int k1 = 1; k1 < 26; k1++)
            {
                cout << "Plain text when k = " << k1 << " : ";
                for (int i = 0; i < str.length(); i++)
                {
                    if (isalpha(str[i]))
                    {
                        if (int(str[i]) - k1 < 65)
                        {
                            cout << char(str[i] - k1 + 26);
                        }
                        else
                        {
                            cout << char(str[i] - k1);
                        }
                    }
                    else
                    {
                        cout << str[i];
                    }
                }
                cout << endl;
            }
            break;
        }
        cout << endl;
    } while (ch != 4);
    cout << endl;
    return 0;
}