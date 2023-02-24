#include <bits/stdc++.h>
using namespace std;

bool checkLength(int length);
bool lowerCase(int length, string line);
bool upperCase(int length, string line);
bool beginLetter(int length, string line);
bool correctDigits(int length, string line);
bool specialChar(int length, string line);
bool consec(int len, string line);
int main()
{
    string fileName;
    ifstream myFile;
    string line;
    int length;
    cout << "Enter password file: ";
    cin >> fileName;
    myFile.open(fileName.c_str());
    if (myFile.is_open())
    {
        cout << "File exists and is ready to be used\n"
             << endl;
        while (!myFile.eof())
        {
            getline(myFile, line);
            length = line.length();
            cout << "Proposed Password: " << line << endl;
            if (checkLength(length) == false || lowerCase(length, line) == false || upperCase(length, line) == false || correctDigits(length, line) == false || specialChar(length, line) == false || consec(length, line) == false)
            {
                cout << "Password is Invalid\n"
                     << endl;
            }
            else
            {
                cout << "Password is Valid\n"
                     << endl;
            }
        }
        myFile.close();
    }
    else
    {
        cerr << "Unable to open file " << fileName << " - does not exist in current directory";
        return 1;
    }
    return 0;
}
int isNumber(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
        if (isdigit(s[i]))
            n++;
    return n;
}
int isSpecial(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (!isalnum(s[i]))
        {
            n++;
        }
    }
    return n;
}
int isAllLower(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (islower(s[i]))
            n++;
    }
    return n;
}
int isAllUpper(string s)
{
    int n = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s[i]))
            n++;
    }
    return n;
}

bool consec(int len, string line)
{
    bool valid;
    for (int i = 0; i < len; i++)
    {
        if (i + 3 < len + 1)
        {
            string sub = line.substr(i, 3);
            cout << sub << ":"
                 << "n : " << isNumber(sub) << " s : " << isSpecial(sub) << " l: " << isAllLower(sub) << " u: " << isAllUpper(sub) << endl;
            if (isNumber(sub) == 3)
            {
                cout << "Consecutive Numbers";
                return false;
            }
            if (isSpecial(sub) == 3)
            {
                cout << "Consecutive Special Character";
                return false;
            }
            if (isAllLower(sub) == 3)
            {
                cout << "All Lower";
                return false;
            }
            if (isAllUpper(sub) == 3)
            {
                cout << "All Upper";
                return false;
            }
        }
    }
    return true;
}
bool checkLength(int length)
{
    bool validLength;
    if ((length >= 10) && (length <= 15))
    {
        validLength = true;
    }
    else
    {
        validLength = false;
        cout << "   Error - The password must be between 10 and 15 characters" << endl;
    }
    return validLength;
}
bool lowerCase(int length, string line)
{

    if (isAllLower(line) < 1)
    {
        cout << "Error - Must have at least 1 lower Case letter" << endl;
        return false;
    }

    return true;
}
bool upperCase(int length, string line)
{

    if (isAllUpper(line) < 1)
    {
        cout << "Error - Must have at least 1 Upper Case letter" << endl;
        return false;
    }
    return true;
}
bool specialChar(int length, string line)
{
    if (isSpecial(line) < 1)
    {
        cout << "Error - Must have atleast 1 special characters" << endl;
        return false;
    }
    return true;
}
bool correctDigits(int length, string line)
{
    if (isNumber(line) < 1)
    {
        cout << "Error - Must have at least one digit" << endl;
        return false;
    }
    return true;
}
