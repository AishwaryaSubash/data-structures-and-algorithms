// PLAYFAIR CIPHER

#include <bits/stdc++.h>
using namespace std;

void matrixgeneration(vector<vector<char>> &matrix, string keyword)
{
    // all characters one line
    vector<char> v;
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

    // 5x5 matrix
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
}

int main()
{
    vector<vector<char>> matrix;
    int ch;
    do
    {
        cout << "\n 1.Generation of Key Matrix \n 2.Cipher \n 3.Decipher \n 4.Exit" << endl;
        cout << " Enter option : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            string keyword;
            cin.ignore();
            cout << "Enter keyword : ";
            getline(cin, keyword);
            matrix.clear();
            transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
            matrixgeneration(matrix, keyword);
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    cout << matrix.at(i).at(j) << " ";
                }
                cout << endl;
            }
            break;
        }
        case 2:
        {
            string text, keyword;
            cout << "Enter plain text : ";
            cin.ignore();
            getline(cin, text);
            cout << "Enter keyword : ";
            getline(cin, keyword);
            matrix.clear();
            transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
            transform(text.begin(), text.end(), text.begin(), ::toupper);
            matrixgeneration(matrix, keyword);

            // Pairing
            vector<pair<char, char>> p;
            for (int i = 0; i < text.length(); i += 2)
            {
                if (isalpha(text[i]))
                {
                    char text1 = text[i] == 'J' ? 'I' : text[i];
                    char text2 = text[i + 1] == 'J' ? 'I' : text[i + 1];
                    if (text1 == text2)
                    {
                        // Pairing first redundant char with X
                        p.push_back(make_pair(text1, 'X'));
                        i--; // Starting again from text2
                    }
                    else
                    {
                        if (isalpha(text1) && isalpha(text2))
                            p.push_back(make_pair(text1, text2));
                        else
                        {
                            // End-Of-Text case
                            if (!isalpha(text2))
                            {
                                p.push_back(make_pair(text1, 'X'));
                            }
                        }
                    }
                }
                else
                {
                    // 2 at a time, so -1
                    i--;
                }
            }

            vector<int> f;
            vector<int> l;
            string ans = ""; // Cipher text

            for (int k = 0; k < p.size(); k++)
            {
                // Indexing the pairs
                int itfi = -1;
                int itfj = -1;
                int itli = -1;
                int itlj = -1;

                // Looping over entire matrix to find the pair coords
                for (int x = 0; x < 5; x++)
                {
                    for (int y = 0; y < 5; y++)
                    {
                        if (p.at(k).first == matrix.at(x).at(y))
                        {
                            itfi = x;
                            itfj = y;
                        }
                        if (p.at(k).second == matrix.at(x).at(y))
                        {
                            itli = x;
                            itlj = y;
                        }
                    }
                }

                // For every pair, insert the coords
                if (itfi != -1 && itfj != -1 && f.empty())
                {
                    f.push_back(itfi);
                    f.push_back(itfj);
                }
                if (itli != -1 && itlj != -1 && l.empty())
                {
                    l.push_back(itli);
                    l.push_back(itlj);
                }

                if (!f.empty() && !l.empty())
                {
                    // Same row
                    if (f.front() == l.front())
                    {
                        // First elem in pair
                        // Interior row
                        if (f.back() + 1 < 5)
                        {
                            ans += matrix.at(f.front()).at(f.back() + 1);
                        }
                        // Last elem in row, so wrap arnd
                        else
                        {
                            ans += matrix.at(f.front()).at(0);
                        }
                        // Second elem in pair
                        // Interior row
                        if (l.back() + 1 < 5)
                        {
                            ans += matrix.at(l.front()).at(l.back() + 1);
                        }
                        // Last elem in row, so wrap arnd
                        else
                        {
                            ans += matrix.at(l.front()).at(0);
                        }
                    }

                    // Same column
                    else if (f.back() == l.back())
                    {
                        // First elem in pair
                        // Interior col
                        if (f.front() + 1 < 5)
                        {
                            ans += matrix.at(f.front() + 1).at(f.back());
                        }
                        // Last elem in col, so wrap arnd
                        else
                        {
                            ans += matrix.at(0).at(f.back());
                        }
                        // Second elem in pair
                        // Interior col
                        if (l.front() + 1 < 5)
                        {
                            ans += matrix.at(l.front() + 1).at(l.back());
                        }
                        // Last elem in col, so wrap arnd
                        else
                        {
                            ans += matrix.at(0).at(f.back());
                        }
                    }
                    // Diagonal mapping
                    else
                    {
                        ans += matrix.at(f.front()).at(l.back());
                        ans += matrix.at(l.front()).at(f.back());
                    }
                    f.clear();
                    l.clear();
                }
            }
            cout << "Cipher Text: " << ans << endl;
            break;
        }
        case 3:
        {
            string text, keyword;
            cout << "Enter cipher text : ";
            cin.ignore();
            getline(cin, text);
            cout << "Enter keyword : ";
            getline(cin, keyword);
            matrix.clear();
            transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
            transform(text.begin(), text.end(), text.begin(), ::toupper);
            matrixgeneration(matrix, keyword);
            vector<int> f;
            vector<int> l;
            string ans = "";
            vector<pair<char, char>> p;

            // Pairing
            for (int i = 0; i < text.size(); i += 2)
            {
                if (isalpha(text[i]))
                {
                    char text1 = text[i] == 'J' ? 'I' : text[i];
                    char text2 = text[i + 1] == 'J' ? 'I' : text[i + 1];
                    if (text1 == text2)
                    {
                        p.push_back(make_pair(text1, 'X'));
                        i--;
                    }
                    else
                    {
                        if (isalpha(text1) && isalpha(text2))
                            p.push_back(make_pair(text1, text2));
                        else
                        {
                            if (!isalpha(text2))
                            {
                                p.push_back(make_pair(text1, 'X'));
                            }
                        }
                    }
                }
                else
                {
                    i--;
                }
            }

            for (int k = 0; k < p.size(); k++)
            {
                int itfi = -1;
                int itfj = -1;
                int itli = -1;
                int itlj = -1;
                for (int x = 0; x < 5; x++)
                {
                    for (int y = 0; y < 5; y++)
                    {
                        if (p.at(k).first == matrix.at(x).at(y))
                        {
                            itfi = x;
                            itfj = y;
                        }
                        if (p.at(k).second == matrix.at(x).at(y))
                        {
                            itli = x;
                            itlj = y;
                        }
                    }
                }
                if (itfi != -1 && itfj != -1 && f.empty())
                {
                    f.push_back(itfi);
                    f.push_back(itfj);
                }
                if (itli != -1 && itlj != -1 && l.empty())
                {
                    l.push_back(itli);
                    l.push_back(itlj);
                }
                if (!f.empty() && !l.empty())
                {
                    // Same row
                    if (f.front() == l.front())
                    {
                        // interior
                        if (f.back() - 1 >= 0)
                        {
                            ans += matrix.at(f.front()).at(f.back() - 1);
                        }
                        // wrap arnd
                        else
                        {
                            ans += matrix.at(f.front()).at(4);
                        }
                        if (l.back() - 1 >= 0)
                        {
                            ans += matrix.at(l.front()).at(l.back() - 1);
                        }
                        else
                        {
                            ans += matrix.at(l.front()).at(4);
                        }
                    }
                    // same col
                    else if (f.back() == l.back())
                    {
                        if (f.front() - 1 >= 0)
                        {
                            ans += matrix.at(f.front() - 1).at(f.back());
                        }
                        else
                        {
                            ans += matrix.at(4).at(f.back());
                        }
                        if (l.front() - 1 >= 0)
                        {
                            ans += matrix.at(l.front() - 1).at(l.back());
                        }
                        else
                        {
                            ans += matrix.at(4).at(f.back());
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
            cout << "Plain Text: " << ans << endl;
            break;
        }
        }
    } while (ch != 4);
    return 0;
}
