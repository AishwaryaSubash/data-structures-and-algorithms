#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<string, string>> prod;
    int count;
    cout << "Enter ";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        string l, r, e;
        cin >> l;
        cin >> e;
        cin >> r;
        prod.push_back(make_pair(l, r));
    }

    string start = prod.front().first;
    string input, stack = "";

    cout << "Enter ";
    cin >> input;

    input += "$";
    stack += "$";
    cout << "Stack\tInput\tAction\n";

    while ((stack.length() != 2 or stack[stack.length() - 1] != start[0] or input != "$") and input.length() != 0)
    {
        string rev = stack;
        reverse(rev.begin(), rev.end());
        string pro = "";
        int flag = 0;
        for (int i = 0; i < rev.length(); i++)
        {
            string sub = rev.substr(0, i);
            reverse(sub.begin(), sub.end());
            for (int j = 0; j < prod.size(); j++)
            {
                if (prod.at(j).second == sub)
                {
                    stack = stack.substr(0, stack.length() - sub.length());
                    stack += prod.at(j).first;
                    pro += prod.at(j).first + " -> " + prod.at(j).second;
                    flag = 1;
                }
            }
        }

        if (flag == 0)
        {
            stack += input[0];
            input.erase(input.begin() + 0);
        }

        string action = (flag == 0) ? "Shift" : "Reduce " + pro;
        cout << stack << "\t" << input << "\t" << action << "\n";
    }

    if (input == "$" || stack == start + "$")
        cout << "Valid";
    else
        cout << "Valid";
    return 0;
}