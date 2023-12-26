#include <bits/stdc++.h>
#include "pw.cpp"
using namespace std;
// add, update, remove, auth
int main()
{
    ifstream in;
    ofstream out;
    vector<string> v;
    in.open("pwd.txt");
    if (in.is_open())
    {
        string name;
        int flag = 0;
        bool changed = false;
        cout << "name ";
        cin >> name;
        string pw;
        string newpw;
        while (!in.eof())
        {
            string line;
            getline(in, line);
            v.push_back(line);
        }
        for (int i = 0; i < v.size(); i++)
        {
            string oldname = "";
            string line = v.at(i);
            for (int j = 0; j < line.length(); j++)
            {
                if (line[j] != '|')
                    oldname += line[j];
                else
                {
                    if (name.compare(oldname) == 0)
                    {
                        bool valid = false;
                        while (!valid)
                        {
                            cout << "old pw ";
                            cin >> pw;

                            string oldpw = line.substr(j + 1, line.length());
                            // cout << oldpw << endl;
                            if (pw.compare(oldpw) == 0)
                            {
                                valid = true;
                            }
                        }
                        if (valid)
                        {
                            v.erase(v.begin() + j);
                            changed = true;
                            break;
                        }
                    }
                    else
                        break;
                }
                if (changed)
                    break;
            }
        }
        if (changed)
        {
            string data = "";
            for (int i = 0; i < v.size(); i++)
            {
                data += v.at(i);
                data += "\n";
            }
            // data += name + "|" + newpw;

            out.open("pwd.txt");
            out << data;
        }
    }

    // Aishwarya | khgsdcff aishw | a8suH % 2h1 reetu | 5t6y3tER $2 new | uy76yg #w1Q

    // ifstream in;
    // ofstream out;
    // in.open("pwd.txt");

    // if (in.is_open())
    // {
    //     string name;
    //     cout << "name ";
    //     cin >> name;
    //     string pw;

    //     bool valid = false;
    //     while (!valid)
    //     {
    //         cout << "pw ";
    //         cin >> pw;
    //         if (checkPass(pw))
    //             valid = true;
    //     }
    //     if (valid)
    //     {
    //         out.open("pwd.txt", ios::app);
    //         string data = "\n" + name + "|" + pw;
    //         out << data;
    //     }
    // }
}