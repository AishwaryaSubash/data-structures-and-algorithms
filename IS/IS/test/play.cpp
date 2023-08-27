#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> matrix;

void matrixGen(string kw)
{
    vector<char> v;
    for (int i = 0; i < kw.length(); i++)
    {
        if (isalpha(kw[i]))
        {
            if (kw[i] == 'I' || kw[i] == 'J')
            {
                if (find(v.begin(), v.end(), 'I') == v.end())
                    v.push_back('I');
            }
            else
            {
                if (find(v.begin(), v.end(), kw[i]) == v.end())
                    v.push_back(kw[i]);
            }
        }
    }

    for (char x = 'A'; x <= 'Z'; x++)
    {
        if (x != 'J')
        {
            if (find(v.begin(), v.end(), x) == v.end())
            {
                v.push_back(x);
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
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.at(i).size(); j++)
        {
            cout << matrix.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

int main()
{

    string kw;
    cout << "kw ";
    cin >> kw;

    matrixGen(kw);
}