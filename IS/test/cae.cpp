#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ch;
    do
    {
        cout << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            string pt = "";
            int k;
            cout << "Enter pt: ";
            cin.ignore();
            getline(cin, pt);
            cout << "Enter key: ";
            cin >> k;
            k %= 25;
            transform(pt.begin(), pt.end(), pt.begin(), ::toupper);
            for (int i = 0; i < pt.length(); i++)
            {
                if (isalpha(pt[i]))
                {
                    if (int(pt[i]) + k > 90)
                    {
                        cout << char(pt[i] + k - 26);
                    }
                    else
                    {
                        cout << char(pt[i] + k);
                    }
                }
                else
                {
                    cout << pt[i];
                }
            }
            break;
        }
        case 2:
        {
            string pt = "";
            int k;
            cout << "Enter ct: ";
            cin.ignore();
            getline(cin, pt);
            cout << "Enter key: ";
            cin >> k;
            k %= 25;
            transform(pt.begin(), pt.end(), pt.begin(), ::toupper);
            for (int i = 0; i < pt.length(); i++)
            {
                if (isalpha(pt[i]))
                {
                    if (int(pt[i]) - k < 65)
                    {
                        cout << char(pt[i] - k + 26);
                    }
                    else
                    {
                        cout << char(pt[i] - k);
                    }
                }
                else
                {
                    cout << pt[i];
                }
            }
            break;
        }
        case 3:
        {
            string pt = "";
            string ct = "";
            cout << "Enter ct: ";
            cin.ignore();
            getline(cin, pt);

            transform(pt.begin(), pt.end(), pt.begin(), ::toupper);

            for (int k = 1; k < 26; k++)
            {
                for (int i = 0; i < pt.length(); i++)
                {
                    if (isalpha(pt[i]))
                    {
                        if (int(pt[i]) - k < 65)
                        {
                            cout << char(pt[i] - k + 26);
                        }
                        else
                        {
                            cout << char(pt[i] - k);
                        }
                    }
                    else
                    {
                        cout << pt[i];
                    }
                }
                cout << endl;
            }
            break;
        }
        }
    } while (ch != 3);
}