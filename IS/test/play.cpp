#include <bits/stdc++.h>
using namespace std;

void matGen(vector<vector<char>> &mat, string kw)
{
    vector<char> v;
    for (int i = 0; i < kw.length(); i++)
    {
        if (isalpha(kw[i]))
        {
            if (kw[i] == 'I' || kw[i] == 'J')
            {
                if (find(v.begin(), v.end(), 'I') == v.end() || find(v.begin(), v.end(), 'J') == v.end())
                    v.push_back('I');
            }
            else
            {
                if (find(v.begin(), v.end(), kw[i]) == v.end())
                    v.push_back(kw[i]);
            }
        }
    }

    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (find(v.begin(), v.end(), c) == v.end())
        {
            if (c != 'J')
                v.push_back(c);
        }
    }

    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        vector<char> n;
        for (int j = 0; j < 5; j++)
        {
            n.push_back(v.at(k++));
        }
        mat.push_back(n);
        n.clear();
    }
}

int main()
{
    int ch;
    do
    {
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            string kw = "";
            cout << "Enter kw: ";
            cin.ignore();
            getline(cin, kw);
            transform(kw.begin(), kw.end(), kw.begin(), ::toupper);
            vector<vector<char>> mat;
            matGen(mat, kw);
            for (vector<char> m : mat)
            {
                for (char c : m)
                {
                    cout << c << " ";
                }
                cout << endl;
            }
            break;
        }
        case 2:
        {
            string oldpt = "";
            cout << "Enter pt: ";
            cin.ignore();
            getline(cin, oldpt);

            string oldkw = "";
            cout << "Enter kw: ";
            getline(cin, oldkw);

            string pt = "";
            string kw = "";

            for (int i = 0; i < oldpt.length(); i++)
            {
                if (isalpha(oldpt[i]))
                {
                    pt += oldpt[i];
                }
            }
            for (int i = 0; i < oldkw.length(); i++)
            {
                if (isalpha(oldkw[i]))
                {
                    kw += oldkw[i];
                }
            }
            transform(pt.begin(), pt.end(), pt.begin(), ::toupper);
            transform(kw.begin(), kw.end(), kw.begin(), ::toupper);

            vector<vector<char>> mat;
            matGen(mat, kw);
            // cout << pt << " " << kw << endl;
            vector<pair<char, char>> p;
            for (int i = 0; i < pt.length(); i += 2)
            {
                if (isalpha(pt[i]))
                {
                    char c1 = pt[i] == 'J' ? 'I' : pt[i];
                    char c2 = pt[i] == 'J' ? 'I' : pt[i + 1];
                    if (c1 == c2)
                    {
                        p.push_back(make_pair(c1, 'X'));
                        i--;
                    }
                    else
                    {
                        if (isalpha(c1) && isalpha(c2))
                        {
                            p.push_back(make_pair(c1, c2));
                        }
                        else
                        {
                            p.push_back(make_pair(c1, 'X'));
                        }
                    }
                }
                else
                    i--;
            }
            // for (pair<char, char> i : p)
            // {
            //     cout << i.first << " " << i.second << endl;
            // }
            vector<int> f;
            vector<int> l;
            string ct = "";

            for (int k = 0; k < p.size(); k++)
            {
                int fx = -1;
                int fy = -1;
                int lx = -1;
                int ly = -1;

                for (int x = 0; x < 5; x++)
                {
                    for (int y = 0; y < 5; y++)
                    {
                        if (p.at(k).first == mat.at(x).at(y))
                        {
                            fx = x;
                            fy = y;
                        }
                        if (p.at(k).second == mat.at(x).at(y))
                        {
                            lx = x;
                            ly = y;
                        }
                    }
                }
                if (fx != -1 && fy != -1 && f.empty())
                {
                    f.push_back(fx);
                    f.push_back(fy);
                }
                if (lx != -1 && ly != -1 && l.empty())
                {
                    l.push_back(lx);
                    l.push_back(ly);
                }

                if (!f.empty() && !l.empty())
                {
                    if (f.front() == l.front())
                    {
                        if (f.back() + 1 < 5)
                            ct += mat.at(f.front()).at(f.back() + 1);
                        else
                            ct += mat.at(f.front()).at(0);
                        if (l.back() + 1 < 5)
                            ct += mat.at(l.front()).at(l.back() + 1);
                        else
                            ct += mat.at(l.front()).at(0);
                    }
                    else if (f.back() == l.back())
                    {
                        if (f.front() + 1 < 5)
                            ct += mat.at(f.front() + 1).at(f.back());
                        else
                            ct += mat.at(0).at(f.back());
                        if (l.front() + 1 < 5)
                            ct += mat.at(l.front() + 1).at(l.back());
                        else
                            ct += mat.at(0).at(l.back());
                    }
                    else
                    {
                        ct += mat.at(f.front()).at(l.back());
                        ct += mat.at(l.front()).at(f.back());
                    }
                }

                // cout << "hi";
                f.clear();
                l.clear();
            }
            cout << ct << endl;
            break;
        }
        case 3:
        {
            string oldpt = "";
            cout << "Enter pt: ";
            cin.ignore();
            getline(cin, oldpt);

            string oldkw = "";
            cout << "Enter kw: ";
            getline(cin, oldkw);

            string pt = "";
            string kw = "";

            for (int i = 0; i < oldpt.length(); i++)
            {
                if (isalpha(oldpt[i]))
                {
                    pt += oldpt[i];
                }
            }
            for (int i = 0; i < oldkw.length(); i++)
            {
                if (isalpha(oldkw[i]))
                {
                    kw += oldkw[i];
                }
            }
            transform(pt.begin(), pt.end(), pt.begin(), ::toupper);
            transform(kw.begin(), kw.end(), kw.begin(), ::toupper);

            vector<vector<char>> mat;
            matGen(mat, kw);
            // cout << pt << " " << kw << endl;
            vector<pair<char, char>> p;
            for (int i = 0; i < pt.length(); i += 2)
            {
                if (isalpha(pt[i]))
                {
                    char c1 = pt[i] == 'J' ? 'I' : pt[i];
                    char c2 = pt[i] == 'J' ? 'I' : pt[i + 1];
                    if (c1 == c2)
                    {
                        p.push_back(make_pair(c1, 'X'));
                        i--;
                    }
                    else
                    {
                        if (isalpha(c1) && isalpha(c2))
                        {
                            p.push_back(make_pair(c1, c2));
                        }
                        else
                        {
                            p.push_back(make_pair(c1, 'X'));
                        }
                    }
                }
                else
                    i--;
            }
            // for (pair<char, char> i : p)
            // {
            //     cout << i.first << " " << i.second << endl;
            // }
            vector<int> f;
            vector<int> l;
            string ct = "";

            for (int k = 0; k < p.size(); k++)
            {
                int fx = -1;
                int fy = -1;
                int lx = -1;
                int ly = -1;

                for (int x = 0; x < 5; x++)
                {
                    for (int y = 0; y < 5; y++)
                    {
                        if (p.at(k).first == mat.at(x).at(y))
                        {
                            fx = x;
                            fy = y;
                        }
                        if (p.at(k).second == mat.at(x).at(y))
                        {
                            lx = x;
                            ly = y;
                        }
                    }
                }
                if (fx != -1 && fy != -1 && f.empty())
                {
                    f.push_back(fx);
                    f.push_back(fy);
                }
                if (lx != -1 && ly != -1 && l.empty())
                {
                    l.push_back(lx);
                    l.push_back(ly);
                }

                if (!f.empty() && !l.empty())
                {
                    if (f.front() == l.front())
                    {

                        if (f.back() - 1 >= 0)
                            ct += mat.at(f.front()).at(f.back() - 1);
                        else
                            ct += mat.at(f.front()).at(4);
                        if (l.back() - 1 >= 0)
                            ct += mat.at(l.front()).at(l.back() - 1);
                        else
                            ct += mat.at(l.front()).at(4);
                    }
                    else if (f.back() == l.back())
                    {
                        if (f.front() - 1 >= 0)
                            ct += mat.at(f.front() - 1).at(f.back());
                        else
                            ct += mat.at(4).at(f.back());
                        if (l.front() - 1 >= 0)
                            ct += mat.at(l.front() - 1).at(l.back());
                        else
                            ct += mat.at(4).at(l.back());
                    }
                    else
                    {
                        ct += mat.at(f.front()).at(l.back());
                        ct += mat.at(l.front()).at(f.back());
                    }
                }

                // cout << "hi";
                f.clear();
                l.clear();
            }
            cout << ct << endl;
            break;
        }
        }
    } while (ch != 4);
}