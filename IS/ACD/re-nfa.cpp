#include <bits/stdc++.h>
using namespace std;

int nodec = 0;

struct State
{
    int num;
    vector<int> a;
    vector<int> b;
};

int main()
{
    string regex;
    cout << "Enter regex ";
    getline(cin, regex);

    vector<State> graph;
    graph.push_back(State()); // 0th state

    for (int i = 0; i < regex.length(); i++)
    {
        if (regex[i] == '(')
        {
            string ch = "";
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
                graph.back().num = nodec;
                for (int j = 0; j < ch.length(); j++)
                {
                    if (ch[j] == 'a')
                        graph.back().a.push_back(nodec);
                    if (ch[j] == 'b')
                        graph.back().b.push_back(nodec);
                }
            }
            else
            {
                State state = State();
                state.num = ++nodec;
                for (int k = 0; k < ch.length(); k++)
                {
                    if (ch[k] == 'a')
                        graph.back().a.push_back(nodec);
                    if (ch[k] == 'b')
                        graph.back().b.push_back(nodec);
                }
                graph.push_back(state);
            }
        }
        else if (regex[i] == 'a')
        {
            graph.back().a.push_back(++nodec);
            State state = State();
            state.num = nodec;
            graph.push_back(state);
        }
        else if (regex[i] == 'b')
        {
            graph.back().b.push_back(++nodec);
            State state = State();
            state.num = nodec;
            graph.push_back(state);
        }
    }
    cout << "State\ta\tb" << endl;
    for (int j = 0; j < graph.size(); j++)
    {
        cout << graph.at(j).num << "\t";
        for (int l = 0; l < graph.at(j).a.size(); l++)
            cout << graph.at(j).a.at(l) << " ";
        cout << "\t";
        for (int l = 0; l < graph.at(j).b.size(); l++)
            cout << graph.at(j).b.at(l) << " ";
        cout << endl;
    }
}