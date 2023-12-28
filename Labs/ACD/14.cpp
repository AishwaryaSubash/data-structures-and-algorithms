// Code gen

#include <bits/stdc++.h>
using namespace std;

vector<string> cg;
stack<int> freereg;
map<int, char> varreg;

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
            result += c;
        else if (c == '(')
            stack.push(c);
        else if (c == ')')
        {
            while (!stack.empty() && stack.top() != '(')
            {
                result += stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() != '(')
                return "Invalid expression";
            else
                stack.pop();
        }
        else
        {
            while (!stack.empty() && Prec(c) <= Prec(stack.top()))
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

string to_string1(int v)
{
    ostringstream oss;
    oss << v;
    return oss.str();
}

string convertsymbol(char ch)
{
    switch (ch)
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

int load(char operand)  //returns reg
{
    map<int, char>::iterator it = varreg.begin();
    while (it != varreg.end())
    {
        if (it->second == operand) // use the same reg
            return it->first;
        it++;
    }

    int reg = freereg.top();
    varreg[reg] = operand;
    freereg.pop();

    string instr = "";
    instr += "LD  R" + to_string1(reg) + ", " + operand;
    cg.push_back(instr);
    return reg;
}

bool found(vector<pair<char, string>> icg, int i, char var)
{
    for (int j = i + 1; j < icg.size(); j++)
    {
        string expr = icg.at(j).second;
        for (int k = 0; k < expr.length(); k++)
            if (expr[k] == var)
                return true;
    }
    return false;
}

int main()
{
    vector<pair<char, string>> icg;
    string start;
    string eq;
    string input;
    cin >> start;
    cin >> eq;
    cin >> input;
    string temp = "";
    char t = 'p';
    int k = 1;
    string postfix = infixToPostfix(input);
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

    //operations
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
            instr += convertsymbol(expr[1]) + " R" + to_string1(reg1) + ", R" + to_string1(reg1) + ", R" + to_string1(reg2);
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
            instr += convertsymbol(expr[1]) + " R" + to_string1(reg2) + ", R" + to_string1(reg1) + ", R" + to_string1(reg2);
            varreg[reg2] = icg.at(i).first;
        }
        else
        {
            int newreg = freereg.top();
            instr += convertsymbol(expr[1]) + " R" + to_string1(newreg) + ", R" + to_string1(reg1) + ", R" + to_string1(reg2);
            varreg[newreg] = icg.at(i).first;
            freereg.pop();
        }
        cg.push_back(instr);
    }

    //store
    char result = icg.back().first;
    string instr = "ST  ";
    instr += result;
    instr += ", R" + to_string1(varreg.rbegin()->first);
    cg.push_back(instr);
    cout << endl;

    for (int i = 0; i < cg.size(); i++)
        cout << cg.at(i) << endl;
    return 0;
}