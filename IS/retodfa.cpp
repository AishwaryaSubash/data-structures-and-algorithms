#include <bits/stdc++.h>
using namespace std;
int nodecount = 0;
struct States
{
    int num;
    vector<int> a;
    vector<int> b;
};
struct Node
{
    struct Node *Next;
    int node_no;
    string nextA;
    string nextB;
};
struct Node *Head, *p, *Temp;
struct Node *create()
{
    Temp = (struct Node *)malloc(sizeof(struct Node));
    Temp->node_no = nodecount;
    nodecount++;
    Temp->Next = NULL;
    return Temp;
}
void update(struct Node *p, char Ch)
{
    string c;
    if (Ch == 'a')
    {
        c = to_string(p->node_no);
        p->nextA += c;
    }
    else if (Ch == 'b')
    {
        c = to_string(p->node_no);
        p->nextB += c;
    }
}
int main()
{
    string prev = "";
    string regex = "", ch = "";
    cout << "Enter Regex : ";
    cin >> regex;
    Head = create();
    p = Head;
    string c = "";
    for (int i = 0; i < regex.length(); i++)
    {
        if (regex[i] == '(')
        {
            string prev = "";
            while (regex[i] != ')')
            {
                if (regex[i] == 'a' || regex[i] == 'b')
                {
                    ch += regex[i];
                }
                i++;
            }
            if (regex[i + 1] == '*')
            {
                for (int j = 0; j < ch.length(); j++)
                {
                    update(p, ch[j]);
                }
                i++;
            }
            if (regex[i + 1] == '+')
            {
                Temp = create();
                c = to_string(Temp->node_no);
                p->nextA += c;
                p->nextB += c;
                p->Next = Temp;
                p = Temp;
                for (int j = 0; j < ch.length(); j++)
                {
                    update(p, ch[j]);
                }
            }
        }
        else if (regex[i] == '+')
        {
            prev = regex[i - 1];
            update(p, prev[0]);
        }
        else if (regex[i + 1] == '*')
        {
            prev = regex[i];
            update(p, prev[0]);
            i++;
        }
        else
        {
            Temp = create();
            p->Next = Temp;
            c = to_string(Temp->node_no);
            if (regex[i] == 'a')
                p->nextA += c;
            else if (regex[i] == 'b')
                p->nextB += c;
            p = Temp;
        }
    }
    cout << "\nNFA Transition table";
    cout << "\n|\tState\t|\ta\t|\tb\t|";
    p = Head;
    struct States states[nodecount];
    for (int j = 0; j < nodecount; j++)
    {
        states[j].num = p->node_no;
        cout << "\n|\t" << p->node_no;

        if (p->nextA.empty())
        {
            cout << "\t|\tnull";
            // states[j].a.push_back(-1);
        }
        else
        {
            cout << "\t|\t";
            for (int i = 0; i < p->nextA.length(); i++)
            {
                cout << p->nextA[i] << " ";
                string temp = "";
                temp += p->nextA[i];
                states[j].a.push_back(stoi(temp));
            }
        }
        if (p->nextB.empty())
        {
            cout << "\t|\tnull\t|";
            // states[j].b.push_back(-1);
        }
        else
        {
            cout << "\t|\t";
            for (int i = 0; i < p->nextB.length(); i++)
            {
                string temp = "";
                cout << p->nextB[i] << " ";
                temp += p->nextB[i];
                states[j].b.push_back(stoi(temp));
            }
            cout << "\t|";
        }
        p = p->Next;
    }

    // for (int j = 0; j < nodecount; j++)
    // {
    //     cout << "\n"
    //          << states[j].num << endl;
    //     for (int i = 0; i < states[j].a.size(); i++)
    //     {
    //         cout << "A : " << states[j].a.at(i) << " ";
    //     }
    //     cout << endl;
    //     for (int i = 0; i < states[j].b.size(); i++)
    //     {
    //         cout << "B : " << states[j].b.at(i) << " ";
    //     }
    // }
    // cout << "\n";
    cout << "\n\nDFA Transition table";
    set<vector<int>> visited;
    vector<set<int>> onA;
    vector<set<int>> onB;
    visited.insert({0});

    for (vector<int> i : visited)
    {
        set<int> tempA;
        set<int> tempB;
        for (int j : i)
        {
            if (!states[j].a.empty())
            {
                for (int k = 0; k < states[j].a.size(); k++)
                {
                    tempA.insert(states[j].a.at(k));
                }
            }
            if (!states[j].b.empty())
            {
                for (int k = 0; k < states[j].b.size(); k++)
                {
                    tempB.insert(states[j].b.at(k));
                }
            }
        }
        onA.push_back(tempA);
        onB.push_back(tempB);
        visited.insert(vector<int>(tempA.begin(), tempA.end()));
        visited.insert(vector<int>(tempB.begin(), tempB.end()));
    }
    vector<string> visitedStr;
    vector<string> onAStr;
    vector<string> onBStr;
    for (vector<int> i : visited)
    {
        string temp = "";
        for (int j : i)
        {
            temp += (to_string(j) + " ");
        }
        visitedStr.push_back(temp);
    }
    for (set<int> i : onA)
    {
        string temp = "";
        for (int j : i)
        {
            temp += (to_string(j) + " ");
        }
        onAStr.push_back(temp);
    }
    for (set<int> i : onB)
    {
        string temp = "";
        for (int j : i)
        {
            temp += (to_string(j) + " ");
        }
        onBStr.push_back(temp);
    }
    cout << endl;
    cout << "\n|\tState\t|\ta\t|\tb\t|\n";
    for (int i = 0; i < visitedStr.size(); i++)
    {
        cout << "|\t" << visitedStr.at(i) << "\t|\t" << onAStr.at(i) << "\t|\t" << onBStr.at(i) << "\t|" << endl;
    }
    cout << endl;
}