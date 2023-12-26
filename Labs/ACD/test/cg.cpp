#include <bits/stdc++.h>
using namespace std;

vector<string> cg;
stack<int> freereg;
map<int, char> varreg;

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

string to_string1(int n)
{
    ostringstream oss;
    oss << n;
    return oss.str();
}

string convertSymbol(char op)
{
    switch (op)
    {
    case '+':
        return "ADD";
    case '-':
        return "SUB";
    case '*':
        return "MUL";
    case '/':
        return "DIV";
    }
    return "";
}

int load(char operand)
{
    map<int, char>::iterator it = varreg.begin();
    while (it != varreg.end())
    {
        if (it->second == operand)
            return it->first;
        it++;
    }
    int reg = freereg.top();
    freereg.pop();
    varreg[reg] = operand;
    string instr = "";
    instr += "LD R" + to_string1(reg) + ", " + operand;
    cg.push_back(instr);
    return reg;
}

bool found(vector<pair<char, string>> icg, int i, char operand)
{
    for (int j = i + 1; j < icg.size(); j++)
    {
        string expr = icg.at(j).second;
        for (int k = 0; k < expr.length(); k++)
            if (expr[k] == operand)
                return true;
    }
    return false;
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

    icg.back().first = start[0];

    for (int i = 10; i >= 1; i--)
        freereg.push(i);

    for (int i = 0; i < icg.size(); i++)
    {
        string expr = icg.at(i).second;
        int reg1 = load(expr[0]);
        int reg2 = load(expr[2]);

        bool r1f = found(icg, i, expr[0]);
        bool r2f = found(icg, i, expr[2]);

        string instr = "";

        if (!r1f)
        {
            instr += convertSymbol(expr[1]) + " R" + to_string1(reg1) + " R" + to_string1(reg1) + ", R" + to_string1(reg2);
            varreg[reg1] = icg.at(i).first;
            if (!r2f)
            {
                if (reg1 != reg2)
                {
                    freereg.push(reg2);
                    varreg.erase(reg2);
                }
            }
        }
        else if (!r2f)
        {
            instr += convertSymbol(expr[1]) + " R" + to_string1(reg2) + " R" + to_string1(reg1) + ", R" + to_string1(reg2);
            varreg[reg2] = icg.at(i).first;
        }
        else
        {
            int newreg = freereg.top();
            freereg.pop();
            varreg[newreg] = icg.at(i).first;
            instr += convertSymbol(expr[1]) + " R" + to_string1(newreg) + " R" + to_string1(reg1) + ", R" + to_string1(reg2);
        }
        cg.push_back(instr);
    }

    char res = icg.back().first;
    string instr = "ST ";
    instr += res;
    instr += ", R" + to_string1(varreg.rbegin()->first);
    cg.push_back(instr);

    for (int i = 0; i < cg.size(); i++)
        cout << cg.at(i) << endl;
    return 0;
}