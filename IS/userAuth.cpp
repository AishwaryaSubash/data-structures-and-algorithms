#include <bits/stdc++.h>
// #include "pwvalid.cpp"
using namespace std;

bool isValidPw(string pw);

int main()
{
    vector<vector<string>> users;
    int cont = 1;
    int ch;
    string un, pw;
    ifstream inputFile;
    ofstream outputFile;
    do
    {
        cout << "1.Add user\n2.Update Password\n3.Remove user\n4.Authenticate user\nEnter option: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter username";
            cin >> un;
            if (un.length() <= 8 && un.length() >= 0)
            {

                cout << "Enter password";
                cin >> pw;
                // ! Call pwvalid func
                // if (isValidPw(pw))
                if (true)
                {
                    users.push_back({un, pw});
                    outputFile.open("users.txt");
                    if (outputFile.is_open())
                    {
                        outputFile.write((char *)&un, un.length());
                        while (inputFile.read((char *)&un, un.length()))
                        {
                            cout << setw(10) << un;
                            // item.putdata();
                        }
                    }
                    else
                    {
                        cerr << "Unable to update database";
                        return 1;
                    }
                    outputFile.close();
                }
            }
            else
            {
                cout << "Username must be less than or equal to 8 characters";
            }
        }
        }
    } while (cont == 1);
}