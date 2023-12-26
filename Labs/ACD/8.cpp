// SHIFT REDUCE PARSER
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<string, string>> production;

    int count;
    cout << "No. of Production : ";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        string ls, rs, arrow;
        cin >> ls;
        cin >> arrow;
        cin >> rs;
        production.push_back(make_pair(ls, rs));
    }

    string start = production[0].first;

    string input;
    cout << "Enter Input String : ";
    cin >> input;
    input += "$";

    string stack = "";
    stack += "$";

    cout << "Stack      Input      Action\n";
    while ((stack.length() != 2 or stack[stack.length() - 1] != start[0] or input != "$") and input.length() != 0)
    {
        string rev = stack;
        reverse(rev.begin(), rev.end());

        int flag = 0;
        string pro = "";

        for (int i = 0; i < rev.length(); i++)
        {
            string sub = rev.substr(0, i);
            reverse(sub.begin(), sub.end());

            for (int j = 0; j < production.size(); j++)
            {
                if (production[j].second == sub)
                {
                    stack = stack.substr(0, stack.length() - sub.length());
                    stack += production[j].first;
                    flag = 1;
                    pro += production[j].first + " -> " + production[j].second;
                }
            }
        }

        if (flag == 0)
        {
            stack += input[0];
            input.erase(input.begin() + 0);
        }
        string action = (flag == 0)
                            ? "Shift"
                            : "Reduce " + pro;
        cout << stack << "      "
             << input << "      "
             << action << endl;
    }

    if ("$" + start == stack && input == "$")
    {
        cout << "\nInput is valid\n";
    }
    else
    {
        cout << "\nInput is invalid\n";
    }

    return 0;
}
