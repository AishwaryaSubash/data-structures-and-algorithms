#include <bits/stdc++.h>
using namespace std;

int Prec(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

string infixToPost(string exp)
{
    string res = "";
    stack<char> stack;
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        if (isalnum(c))
            res += c;
        else if (c == '(')
            stack.push(c);
        else if (c == ')')
        {
            while (!stack.empty() && stack.top() != '(')
            {
                res += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else
        {
            while (!stack.empty() && Prec(c) <= Prec(stack.top()))
            {
                res += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.empty())
    {
        res += stack.top();
        stack.pop();
    }
    return res;
}

int main()
{
    vector<pair<char, string>> icg;
    string input, eq, start;
    cin >> start;
    cin >> eq;
    cin >> input;

    string postfix = infixToPost(input);
    char t = 'p';
    string temp = "";
    for (int i = 0; i < postfix.length(); i++)
    {
        string expr = "";
        if (!isalpha(postfix[i]))
        {
            expr += temp[temp.length() - 2];
            expr += postfix[i];
            expr += temp[temp.length() - 1];
            temp = temp.substr(0, temp.length() - 2);
            int flag = 0;
            for (int j = 0; j < icg.size(); j++)
            {
                if (icg.at(j).second == expr)
                {
                    temp += icg.at(j).first;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                icg.push_back(make_pair(t, expr));
                temp += t++;
            }
        }
        else
            temp += postfix[i];
    }

    for (int i = 0; i < icg.size(); i++)
        cout << icg.at(i).first << " = " << icg.at(i).second << endl;
    cout << start << " = " << icg.back().first << endl;
}