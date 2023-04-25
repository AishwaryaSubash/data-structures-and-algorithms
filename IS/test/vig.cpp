#include <bits/stdc++.h>
using namespace std;

int main()
{

    int ch;
    string pt;
    string ct;
    string kw;
    do
    {
        cout << "\n1.Matrix\n2.Cipher\n3.Decipher\n4.Exit";
        cout << "\nEnter choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            vector<vector<char>> matrix;
            matrix.clear();
            vector<char> v;
            for (char c = 'A'; c <= 'Z'; c++)
            {
                v.push_back(c);
            }
            for (int i = 0; i < 26; i++)
            {
                matrix.push_back(v);
                char c = v.front();
                v.erase(v.begin());
                v.push_back(c);
            }
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix.at(i).size(); j++)
                {
                    cout << matrix.at(i).at(j) << " ";
                }
                cout << endl;
            }
            break;
        }
        case 2:
        {
            string pt = "";
            cout << "Enter plain text: ";
            cin.ignore();
            getline(cin, pt);
            string kw = "";
            cout << "Enter keyword: ";
            getline(cin, kw);
            // cout << kw << endl;
            string ct = "";
            transform(pt.begin(), pt.end(), pt.begin(), ::toupper);
            transform(kw.begin(), kw.end(), kw.begin(), ::toupper);
            string newPt = "";
            string newKw = "";

            for (int i = 0; i < pt.length(); i++)
            {
                if (isalpha(pt[i]))
                {
                    newPt += pt[i];
                }
            }
            for (int i = 0; i < kw.length(); i++)
            {
                if (isalpha(kw[i]))
                {
                    newKw += kw[i];
                }
            }
            // cout << newPt << " " << newKw;
            while (newKw.length() < newPt.length())
            {
                newKw += newKw;
            }
            newKw = newKw.substr(0, newPt.length());
            // cout << newKw;

            for (int i = 0; i < newPt.length(); i++)
            {
                if (int(newPt[i] + newKw[i]) < (91 + 65))
                {
                    ct += char(newPt[i] + newKw[i] - 65);
                }
                else
                {
                    ct += char(newPt[i] + newKw[i] - 91);
                }
            }
            cout << ct;
            break;
        }
        case 3:
        {
            string pt = "";
            cout << "Enter plain text: ";
            cin.ignore();
            getline(cin, pt);
            string kw = "";
            cout << "Enter keyword: ";
            getline(cin, kw);
            string ct = "";
            transform(pt.begin(), pt.end(), pt.begin(), ::toupper);
            transform(kw.begin(), kw.end(), kw.begin(), ::toupper);
            string newPt = "";
            string newKw = "";

            for (int i = 0; i < pt.length(); i++)
            {
                if (isalpha(pt[i]))
                {
                    newPt += pt[i];
                }
            }
            for (int i = 0; i < kw.length(); i++)
            {
                if (isalpha(kw[i]))
                {
                    newKw += kw[i];
                }
            }
            while (newKw.length() < newPt.length())
            {
                newKw += newKw;
            }
            newKw = newKw.substr(0, newPt.length());

            for (int i = 0; i < newPt.length(); i++)
            {
                if (int(newPt[i] - newKw[i]) >= 0)
                {
                    ct += char(newPt[i] - newKw[i] + 65);
                }
                else
                {
                    ct += char(newPt[i] - newKw[i] + 91);
                }
            }
            cout << ct;
            break;
        }
        }

    } while (ch != 4);
}