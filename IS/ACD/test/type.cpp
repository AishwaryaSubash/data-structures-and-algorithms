#include <bits/stdc++.h>
using namespace std;

string lstrip(string line)
{
    string exp = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] != ' ')
        {
            exp = line.substr(i, line.length());
            break;
        }
    }
    return exp;
}

string rstrip(string line)
{
    reverse(line.begin(), line.end());
    line = lstrip(line);
    reverse(line.begin(), line.end());
    return line;
}

void print(string l, string op, string r, string res)
{
    cout << l << op << r << " = " << res;
}

vector<string> allWords(string line)
{
    vector<string> v;
    string str = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] != ' ')
        {
            str += line[i];
        }
        else
        {
            if (str != "" && str != " ")
                v.push_back(str);
            str = "";
        }
    }
    if (str != "" && str != " ")
        v.push_back(str);
    return v;
}

int prec(string op)
{
    if (op == "double")
        return 3;
    else if (op == "float")
        return 2;
    else if (op == "int")
        return 1;
    return -1;
}

int main()
{
    ifstream file;
    file.open("sampl.c");
    map<string, string> mp;
    if (file.is_open())
    {
        while (!file.eof())
        {
            string line;
            getline(file, line);
            line = lstrip(line);
            line = rstrip(line);
            vector<string> words = allWords(line);

            if (words.front() == "int" || words.front() == "float" || words.front() == "double" || words.front() == "char")
            {
                for (int j = 1; j < words.size(); j++)
                {
                    string var = words.at(j);
                    var = lstrip(var);
                    var = rstrip(var);
                    var = var.substr(0, var.length() - 1);
                    mp[var] = words.front();
                }
            }
        }
        map<string, string>::iterator it = mp.begin();
        while (it != mp.end())
        {
            cout << it->first << " " << it->second << endl;
            it++;
        }
    }
    else
        cout << "error";

    string input;
    cout << endl
         << "input ";
    getline(cin, input);

    vector<string> wordIn = allWords(input);

    if (mp[wordIn.at(0)] == "int" && mp[wordIn.at(2)] == "int" && wordIn.at(1) == "%")
        print(mp[wordIn.at(0)], "%", mp[wordIn.at(2)], "int");
    else if ((mp[wordIn.at(0)] == "int" || mp[wordIn.at(0)] == "float" || mp[wordIn.at(0)] == "double") &&
             (mp[wordIn.at(2)] == "int" || mp[wordIn.at(2)] == "float" || mp[wordIn.at(2)] == "double") &&
             (wordIn.at(1) == "+" || wordIn.at(1) == "-" || wordIn.at(1) == "*" || wordIn.at(1) == "/"))
    {
        if (prec(mp[wordIn.at(0)]) < prec(mp[wordIn.at(2)]))
            print(mp[wordIn.at(0)], wordIn.at(1), mp[wordIn.at(2)], mp[wordIn.at(2)]);
        else
            print(mp[wordIn.at(0)], wordIn.at(1), mp[wordIn.at(2)], mp[wordIn.at(0)]);
    }
    else if ((mp[wordIn.at(0)] == "int" || mp[wordIn.at(0)] == "char") &&
             (mp[wordIn.at(2)] == "int" || mp[wordIn.at(2)] == "char") &&
             (wordIn.at(1) == "+" || wordIn.at(1) == "-"))
        print(mp[wordIn.at(0)], wordIn.at(1), mp[wordIn.at(2)], mp[wordIn.at(2)]);
    else
        cout << "Invalid";

    return 0;
}