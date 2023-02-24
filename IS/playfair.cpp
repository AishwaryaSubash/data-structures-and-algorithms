#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<char>> matrix;
    string text, keyword;
    cout << "Enter plain text : ";
    getline(cin, text);
    cout << "Enter keyword : ";
    getline(cin, keyword);
    vector<char> v;
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
    transform(text.begin(), text.end(), text.begin(), ::toupper);
    for (int i = 0; i < keyword.length(); i++)
    {
        if (isalpha(keyword[i]))
        {
            if (keyword[i] == 'J' || keyword[i] == 'I')
            {
                if (find(v.begin(), v.end(), 'I') == v.end())
                {
                    v.push_back('I');
                }
            }
            else
            {
                if (find(v.begin(), v.end(), keyword[i]) == v.end())
                {
                    v.push_back(keyword[i]);
                }
            }
        }
    }
    for (char i = 'A'; i <= 'Z'; i++)
    {
        if (i != 'J')
        {
            if (find(v.begin(), v.end(), i) == v.end())
            {
                v.push_back(i);
            }
        }
    }
    int k = 0;
    vector<char> c;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            c.push_back(v.at(k++));
        }
        matrix.push_back(c);
        c.clear();
    }
    for (vector<char> i : matrix)
    {
        for (char j : i)
        {

            cout << j << " ";
        }
        cout << endl;
    }
    vector<pair<char, char>> p;
    for (int i = 0; i < text.size(); i += 2)
    {
        if (isalpha(text[i]))
        {
            char text1 = text[i] == 'J' ? 'I' : text[i];
            char text2 = text[i + 1] == 'J' ? 'I' : text[i + 1];
            if (text1 == text2)
            {
                p.push_back({text1, 'X'});
                i--;
            }
            else
            {
                if (isalpha(text1) && isalpha(text2))
                    p.push_back({text1, text2});
                else
                {
                    if (!isalpha(text2))
                    {
                        p.push_back({text1, 'X'});
                    }
                }
            }
        }
        else
        {
            i--;
        }
    }
    for (pair<char, char> i : p)
    {
        cout << i.first << " " << i.second << endl;
    }
    vector<int> f;
    vector<int> l;
    string ans = "";
    for (int k = 0; k < p.size(); k++)
    {
        for (int i = 0; i < 5; i++)
        {
            auto itf = find(matrix.at(i).begin(), matrix.at(i).end(), p.at(k).first);

            auto itl = find(matrix.at(i).begin(), matrix.at(i).end(), p.at(k).second);

            if (itf != matrix.at(i).end() && f.empty())
            {
                f.push_back(i);
                f.push_back(itf - matrix.at(i).begin());
            }
            if (itl != matrix.at(i).end() && l.empty())
            {
                l.push_back(i);
                l.push_back(itl - matrix.at(i).begin());
            }
        }
        if (!f.empty() && !l.empty())
        {
            if (f.front() == l.front())
            {
                if (f.back() + 1 < 5)
                {
                    ans += matrix.at(f.front()).at(f.back() + 1);
                }
                else
                {
                    ans += matrix.at(f.front()).at(0);
                }
                if (l.back() + 1 < 5)
                {
                    ans += matrix.at(l.front()).at(l.back() + 1);
                }
                else
                {
                    ans += matrix.at(l.front()).at(0);
                }
            }
            else if (f.back() == l.back())
            {
                if (f.front() + 1 < 5)
                {
                    ans += matrix.at(f.front() + 1).at(f.back());
                }
                else
                {
                    ans += matrix.at(0).at(f.back());
                }
                if (l.front() + 1 < 5)
                {
                    ans += matrix.at(l.front() + 1).at(l.back());
                }
                else
                {
                    ans += matrix.at(0).at(f.back());
                }
            }
            else
            {
                ans += matrix.at(f.front()).at(l.back());
                ans += matrix.at(l.front()).at(f.back());
            }
            f.clear();
            l.clear();
        }
    }
    cout << ans << endl;
    return 0;
}
