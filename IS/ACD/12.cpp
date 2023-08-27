// ICG
#include <bits/stdc++.h>
using namespace std;

int Prec(char ch)
{
    switch (ch)
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

string infixToPostfix(string exp)
{
    string result = "";
    stack<char> stack;
    for (int i = 0; i < exp.length(); i++)
    {
        char c = exp[i];
        if (isalnum(c))
            result += c; // a * ( b + c )
        else if (c == '(')
            stack.push(c);
        else if (c == ')')
        {
            while (!stack.empty() && stack.top() != '(')
            {
                result += stack.top();
                stack.pop();
            }
            // if (stack.empty() || stack.top() != '(')
            //     return "Invalid expression";
            // else     // removes (
            stack.pop();
        }
        else // operator
        {
            while (!stack.empty() && Prec(c) <= Prec(stack.top())) // low precedence of c
            {
                result += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.empty())
    {
        result += stack.top();
        stack.pop();
    }
    return result;
}

int main()
{
    vector<pair<char, string>> icg;
    string start;
    string eq;
    string input; // abc*+
    cin >> start;
    cin >> eq;
    cin >> input;

    string temp = "";
    char t = 'p'; // LHS
    string postfix = infixToPostfix(input);
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
        cout << endl
             << "temp " << temp << endl;
        cout << "expr " << expr << endl;
    }

    for (int i = 0; i < icg.size(); i++)
        cout << icg.at(i).first << " = " << icg.at(i).second << endl;
    cout << start << " = " << icg.back().first << endl;
    return 0;
}
