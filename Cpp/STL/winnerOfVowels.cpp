#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    return false;
}

int main()
{
    vector<string> str;
    for (int i = 0; i < 5; i++)
    {
        string v = "";
        for (int j = 0; j < 5; j++)
        {
            string word;
            cin >> word;
            v += word;
            v += " ";
        }
        str.push_back(v);
        v.clear();
    }

    vector<pair<int, int>> v;
    for (int i = 0; i < str.size(); i++)
    {
        int count = 0;
        int points = 0;
        for (int j = 0; j < str.at(i).size(); j++)
        {
            if (isVowel(str.at(i).at(j)))
            {
                count++;
            }
        }
        if (count == 0)
            points = 0;
        else if (count == 1)
            points = 1;
        else if (count == 2)
            points = 2;
        else if (count == 3)
            points = 4;
        else if (count == 4)
            points = 5;
        else if (count == 5)
            points = 6;
        else if (count > 5)
            points = 8;

        v.push_back({i + 1, points});
    }

    int max = -1;
    vector<int> m;
    vector<int> po;
    int num = 0;
    for (pair<int, int> p : v)
    {
        if (p.second >= max)
        {
            max = p.second;
        }
    }
    for (pair<int, int> p : v)
    {
        if (p.second == max)
        {
            m.push_back(p.first);
            po.push_back(p.second);
        }
    }
    cout << "Winners: ";
    for (int i = 0; i < m.size(); i++)
    {
        if (i != m.size() - 1)
            cout << m.at(i) << ",";
        else
            cout << m.at(i);
    }
    cout << endl
         << "Points: " << po.at(0) << endl;
}

/*
0-0
1-1
2-2
3-4
4-5
5-6
>5-8

*/