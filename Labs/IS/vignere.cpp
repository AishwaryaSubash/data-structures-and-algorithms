#include <bits/stdc++.h>
using namespace std;

int main()
{
    string pt = "";
    string kw = "";
    string ct = "";
    vector<vector<char>> matrix;
    vector<char> alpha;
    int ch;
    do
    {
        cout << endl
             << " 1.Generation of Key Matrix \n 2.Cipher \n 3.Decipher \n 4.Exit" << endl;
        cout << "\nEnter option : ";
        cin >> ch;
        string newPt = "";
        string newKw = "";
        switch (ch)
        {
        case 1:
            for (char i = 'A'; i <= 'Z'; i++)
                alpha.push_back(i);

            for (int i = 0; i < 26; i++)
            {
                matrix.push_back(alpha);
                char top = alpha.front();
                alpha.erase(alpha.begin());
                alpha.insert(alpha.end(), top);
            }

            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    cout << matrix.at(i).at(j) << " ";
            cout << endl;
            break;

        case 2:
            newPt = "", newKw = "", ct = "";
            cout << "Enter Plaintext: ";
            cin.ignore();

            getline(cin, pt);
            cout << "Enter Keyword: ";
            getline(cin, kw);

            transform(pt.begin(), pt.end(), pt.begin(), ::toupper);
            transform(kw.begin(), kw.end(), kw.begin(), ::toupper);

            for (int i = 0; i < pt.length(); i++)
                if (isalpha(pt[i]))
                    newPt += pt[i];

            for (int i = 0; i < kw.length(); i++)
                if (isalpha(kw[i]))
                    newKw += kw[i];

            while (newKw.length() < newPt.length())
                newKw += newKw;
            newKw = newKw.substr(0, newPt.length());

            for (int i = 0; i < newPt.length(); i++)
            {
                if (int(newPt[i] + newKw[i]) < (91 + 65))
                    ct += char(newPt[i] + newKw[i] - 65);
                else
                    ct += char(newPt[i] + newKw[i] - 91);
            }
            cout << "Ciphertext: " << ct;
            break;

        case 3:
            newPt = "", newKw = "", ct = "";
            cout << "Enter Ciphertext: ";
            cin.ignore();

            getline(cin, pt);
            cout << "Enter Keyword: ";
            getline(cin, kw);

            transform(pt.begin(), pt.end(), pt.begin(), ::toupper);
            transform(kw.begin(), kw.end(), kw.begin(), ::toupper);

            for (int i = 0; i < pt.length(); i++)
                if (isalpha(pt[i]))
                    newPt += pt[i];

            for (int i = 0; i < kw.length(); i++)
                if (isalpha(kw[i]))
                    newKw += kw[i];

            while (newKw.length() < newPt.length())
                newKw += newKw;
            newKw = newKw.substr(0, newPt.length());

            for (int i = 0; i < newPt.length(); i++)
            {
                if (int(newPt[i] - newKw[i]) >= 0)
                    ct += char(newPt[i] - newKw[i] + 65);
                else
                    ct += char(newPt[i] - newKw[i] + 91);
            }
            cout << "Plaintext is: " << ct;
            break;
        }
    } while (ch != 4);
    return 0;
}
