#include <bits/stdc++.h>
using namespace std;
string lstrip(string line)
{
    string str = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] != ' ')
        {
            str = line.substr(i, line.length());
            break;
        }
    }
    return str;
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
    cout << l << op << r << " = " << res << endl;
}
vector<string> allWords(string line)
{
    vector<string> v;
    string str = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] != ' ')
            str += line[i];
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
int main()
{
    ifstream file;
    file.open("sample.c");
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
            if (!words.empty())
            {
                if (words.front() == "int" || words.front() == "float" || words.front() == "double" || words.front() == "char")
                {
                    for (int i = 1; i < words.size(); i++)
                    {
                        string fir = words.at(i);
                        fir = lstrip(fir);
                        fir = rstrip(fir);
                        fir = fir.substr(0, fir.length() - 1);
                        mp[fir] = words.front();
                    }
                }
            }
        }
        map<string, string>::iterator it = mp.begin();
        while (it != mp.end())
        {
            cout << it->first << " -> " << it->second << endl;
            ++it;
        }
        string input;
        cout << "Enter Expression : ";
        getline(cin, input);
        string result = "";
        vector<string> splitWords = allWords(input);
        if (mp[splitWords.at(0)] == "int" && mp[splitWords.at(2)] == "int" && splitWords.at(1) == "%")
            print(mp[splitWords.at(0)], mp[splitWords.at(1)], mp[splitWords.at(2)], mp[splitWords.at(2)]);
        else if ((mp[splitWords.at(0)] == "int" || mp[splitWords.at(0)] == "float" || mp[splitWords.at(0)] == "double") and
                 (mp[splitWords.at(2)] == "int" || mp[splitWords.at(2)] == "float" || mp[splitWords.at(2)] == "double") and
                 (splitWords.at(1) == "+" || splitWords.at(1) == "-" || splitWords.at(1) == "*" || splitWords.at(1) == "/"))
        {
            if (precedence(mp[splitWords.at(0)]) > precedence(mp[splitWords.at(2)]))
                print(mp[splitWords.at(0)], splitWords.at(1), mp[splitWords.at(2)], mp[splitWords.at(0)]);
            else
                print(mp[splitWords.at(0)], splitWords.at(1), mp[splitWords.at(2)], mp[splitWords.at(2)]);
        }
        else if ((mp[splitWords.at(0)] == "int" || mp[splitWords.at(0)] == "char") and
                 (mp[splitWords.at(2)] == "int" || mp[splitWords.at(2)] == "char") and
                 (splitWords.at(1) == "+" || splitWords.at(1) == "-"))
        {
            if (mp[splitWords.at(0)] == mp[splitWords.at(2)])
                print(mp[splitWords.at(0)], splitWords.at(1), mp[splitWords.at(2)], mp[splitWords.at(0)]);
            else
                print(mp[splitWords.at(0)], splitWords.at(1), mp[splitWords.at(2)], "int");
        }
        else
        {
            cout << "Invalid\n";
        }
    }
}
