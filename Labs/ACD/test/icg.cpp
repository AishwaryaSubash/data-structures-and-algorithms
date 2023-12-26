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
    string start, eq, input;
    cin >> start;
    cin >> eq;
    cin >> input;

    string temp = "";
    char t = 'p';
    string postfix = infixToPost(input);
    cout << postfix << endl;

    for (int i = 0; i < postfix.length(); i++)
    {
        string expr = "";
        if (!isalpha(postfix[i]))
        {
            expr += temp[temp.length() - 2];
            expr += postfix[i];
            expr += temp[temp.length() - 1];
            temp = temp.substr(0, temp.length() - 2);
            icg.push_back(make_pair(t, expr));
            temp += t++;
        }
        else
            temp += postfix[i];
    }
    for (int i = 0; i < icg.size(); i++)
        cout << icg.at(i).first << " = " << icg.at(i).second << endl;
    cout << start << " = " << icg.back().first << endl;
}