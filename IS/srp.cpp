#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<string, string>> production;

    int count;
    cout << "Count :";
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
    // for(int i=0;i<production.size();i++){
    //     cout<<production[i].first<<"->"<<production[i].second;
    // }

    string input;
    cin >> input;
    input += "$";
    string stack = "";
    stack += "$";
    while (stack.length() != 2 or stack.back() != start[0] or input != "$")
    {
        string rev = stack;
        reverse(rev.begin(), rev.end());
        int flag = 0;
        for (int i = 0; i < rev.length(); i++)
        {
            string sub = rev.substr(0, i);
            reverse(sub.begin(), sub.end());

            for (int j = 0; j < production.size(); j++) // REDUCE
            { 
                if (production[j].second == sub)
                {
                    int len = sub.length();
                    for (int k = 0; k < len; k++)
                    {
                        stack.pop_back();
                    }
                    stack += production[j].first;
                    flag = 1;
                }
            }
        }
        if (flag == 0) // SHIFT
        { 
            stack += input.front();
            input.erase(input.begin() + 0);
        }
        cout << "Stack : " << stack << " Input : " << input << endl;
    }
}