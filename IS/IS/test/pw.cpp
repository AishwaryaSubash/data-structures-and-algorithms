#include <bits/stdc++.h>
using namespace std;
set<string> error;

int allLower(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
        if (islower(s[i]))
            n++;
    return n;
}

int allUpper(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
        if (isupper(s[i]))
            n++;
    return n;
}

int spclChr(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
        if (!isalnum(s[i]))
            n++;
    return n;
}

int digit(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]))
            n++;
    return n;
}

bool lowercase(string s)
{
    if (allLower(s) < 1)
    {
        error.insert("Atleast 1 lowercase");
        return false;
    }
    return true;
}

bool uppercase(string s)
{
    if (allUpper(s) < 1)
    {
        error.insert("Atleast 1 uppercase");
        return false;
    }
    return true;
}

bool specialCharacters(string s)
{
    if (spclChr(s) < 1)
    {
        error.insert("Atleast 1 special");
        return false;
    }
    return true;
}

bool digitsCount(string s)
{
    if (digit(s) < 1)
    {
        error.insert("Atleast 1 digit");
        return false;
    }
    return true;
}

bool noConsec(string s)
{
    set<char> v(s.begin(), s.end());
    return (v.size() == 1);
}

bool consecutive(string s)
{
    bool valid = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (i + 3 < s.length() + 1)
        {
            string sub = s.substr(i, 3);
            if (allLower(sub) == 3)
            {
                valid = false;
                error.insert("consec lower");
            }
            if (allUpper(sub) == 3)
            {
                valid = false;
                error.insert("consec upper");
            }
            if (spclChr(sub) == 3)
            {
                valid = false;
                error.insert("consec specl");
            }
            if (digit(sub) == 3)
            {
                valid = false;
                error.insert("consec digit");
            }
            if (noConsec(sub))
            {
                valid = false;
                error.insert("consec letters");
            }
        }
    }
    return valid;
}

bool checkLen(string s)
{
    int len = s.length();
    if (len <= 8 && len >= 20)
    {
        error.insert("Length");
        return false;
    }
    return true;
}

bool checkPass(string line)
{

    // error.clear();
    // cout << "Line " << line << endl;
    if (checkLen(line) == false || consecutive(line) == false ||
        digitsCount(line) == false || lowercase(line) == false ||
        uppercase(line) == false || specialCharacters(line) == false)
    {
        // vector<string> v(error.begin(), error.end());
        // for (int i = 0; i < v.size(); i++)
        //     cout << v.at(i) << endl;
        return false;
    }
    else
        // cout << "\nValid\n";
        return true;
    // cout << endl;
}

// int main()
// {
//     ifstream file;
//     file.open("pwd.txt");
//     if (file.is_open())
//     {
//         while (!file.eof())
//         {
//             string line;
//             getline(file, line);
//             error.clear();
//             cout << "Line " << line << endl;
//             if (checkLen(line) == false || consecutive(line) == false ||
//                 digitsCount(line) == false || lowercase(line) == false ||
//                 uppercase(line) == false || specialCharacters(line) == false)
//             {
//                 vector<string> v(error.begin(), error.end());
//                 for (int i = 0; i < v.size(); i++)
//                     cout << v.at(i) << endl;
//             }
//             else
//                 cout << "\nValid\n";
//             cout << endl;
//         }
//     }
//     file.close();
// }