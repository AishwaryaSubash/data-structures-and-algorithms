#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count;
    cout << "Enter count ";
    cin >> count;
    vector<pair<string, string>> production;
    cout << "Enter productions: " << endl;
    for (int i = 0; i < count; i++)
    {
        string ls, rs, ms;
        cin >> ls;
        cin >> ms;
        cin >> rs;
        production.push_back(make_pair(ls, rs));
    }

    // for (int i = 0; i < production.size(); i++)
    // {
    //     cout << production[i].first << " " << production[i].second << endl;
    // }

    string start = production[0].first;
    string input;
    cout << "Enter input string: ";
    cin >> input;
    input += "$";

    string stack = "";
    stack += "$";
    cout << "Stack\t\tInput\t\tAction" << endl;
    while ((input != "$" or stack.back() != start[0] or stack.length() != 2) and !input.empty())
    {
        string rev = stack;
        reverse(rev.begin(), rev.end());
        int flag = 0;
        string pro = "";
        for (int i = 0; i < rev.size(); i++) // REDUCE
        {
            string sub = rev.substr(0, i);
            reverse(sub.begin(), sub.end());
            for (int k = 0; k < production.size(); k++)
            {
                if (production[k].second == sub)
                {
                    for (int j = 0; j < sub.length(); j++)
                    {
                        stack = stack.substr(0, stack.length() - 1);
                    }
                    stack += production[k].first;
                    pro += "Reduce" + production[k].first + "->" + production[k].second;
                    flag = 1;
                }
            }
        }
        if (flag == 0) // SHIFT
        {
            stack += input[0];
            input = input.substr(1, input.length());
            pro += "Shift";
        }
        cout << stack << "\t\t" << input << "\t\t" << pro << endl;
    }
}