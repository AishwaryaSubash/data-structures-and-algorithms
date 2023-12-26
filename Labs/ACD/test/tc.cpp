#include <bits/stdc++.h>
using namespace std;

string lstrip(string line)
{
    string l = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] != ' ')
        {
            l = line.substr(i, line.length());
            break;
        }
    }
    return l;
}

string rstrip(string line)
{
    reverse(line.begin(), line.end());
    line = lstrip(line);
    reverse(line.begin(), line.end());
    return line;
}

int precedence(string line)
{
    if (line == "double")
        return 3;
    else if (line == "float")
        return 2;
    else if (line == "int")
        return 1;
    return -1;
}

void print(string l, string op, string r, string res)
{
    cout << l << op << r << " = " << res;
}

vector<string> allWords(string line)
{
    vector<string> v;
    string l = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] != ' ')
        {
            l += line[i];
        }
        else
        {
            if (l != " " && l != "")
            {
                v.push_back(l);
            }
            l = "";
        }
    }
    if (l != " " && l != "")
    {
        v.push_back(l);
    }
    return v;
}

int main()
{
    ifstream myFile;
    string line;
    int length;
    myFile.open("sample.c");

    if (myFile.is_open())
    {
        map<string, string> mp;
        while (!myFile.eof())
        {
            getline(myFile, line);
            length = line.length();
            vector<string> first = allWords(line);
            if (!first.empty())
            {
                if (first.front() == "int" || first.front() == "float" 
                || first.front() == "double" || first.front() == "char")
                {
                    for (int i = 1; i < first.size(); i++)
                    {
                        string var = first.at(i);
                        var = lstrip(var);
                        var = rstrip(var);
                        var.pop_back();
                        mp[var] = first.front();
                    }
                }
            }
        }
        cout << "Variable->Type" << endl;
        map<string, string>::iterator it = mp.begin();
        while (it != mp.end())
        {
            cout << it->first << " " << it->second << endl;
            ++it;
        }

        string input;
        getline(cin, input);
        vector<string> splitWords = allWords(input);
        string result = "";

        if (mp[splitWords.at(0)] == "int" && mp[splitWords.at(2)] == "int" || splitWords.at(1) == "%")
        {
            print(mp[splitWords.at(0)], splitWords.at(1), mp[splitWords.at(2)], "int");
        }
        else if ((mp[splitWords.at(0)] == "int" || mp[splitWords.at(0)] == "float" || mp[splitWords.at(0)] == "double") and (mp[splitWords.at(2)] == "int" || mp[splitWords.at(2)] == "float" || mp[splitWords.at(2)] == "double") and (splitWords.at(1) == "+" || splitWords.at(1) == "-" || splitWords.at(1) == "*" || splitWords.at(1) == "/"))
        {
            if (precedence(mp[splitWords.at(0)]) > precedence(mp[splitWords.at(2)]))
                result = mp[splitWords.at(0)];
            else
                result = mp[splitWords.at(2)];
            print(mp[splitWords.at(0)], splitWords.at(1), mp[splitWords.at(2)], result);
        }
        else if ((mp[splitWords.at(0)] == "int" || mp[splitWords.at(0)] == "char") and (mp[splitWords.at(2)] == "int" || mp[splitWords.at(2)] == "char") and (splitWords.at(1) == "+" || splitWords.at(1) == "-"))
        {
            if (mp[splitWords.at(0)] == mp[splitWords.at(2)])
                result = mp[splitWords.at(2)];
            else
                result = "int";
            print(mp[splitWords.at(0)], splitWords.at(1), mp[splitWords.at(2)], result);
        }
        else
        {
            cout << "Invalid";
        }
    }
}