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
    graph.push_back(State());

    for (int i = 0; i < regex.length(); i++)
    {
        if (regex[i] == '(')
        {
            string ch = "";
            while (regex[i] != ')')
            {
                if (regex[i] == 'a' || regex[i] == 'b')
                    ch += regex[i];
                i++;
            }
            if (regex[i + 1] == '*')
            {
                graph.back().num = nodec;
                for (int j = 0; j < ch.length(); j++)
                {
                    if (ch[j] == 'a')
                        graph.back().a.push_back(nodec);
                    else if (ch[j] == 'b')
                        graph.back().b.push_back(nodec);
                }
            }
            else
            {
                State state = State();
                state.num = ++nodec;
                for (int j = 0; j < ch.length(); j++)
                {
                    if (ch[j] == 'a')
                        graph.back().a.push_back(nodec);
                    else if (ch[j] == 'b')
                        graph.back().b.push_back(nodec);
                }
                graph.push_back(state);
            }
        }
        else if (regex[i] == 'a')
        {
            State state = State();
            state.num = ++nodec;
            graph.back().a.push_back(nodec);
            graph.push_back(state);
        }
        else if (regex[i] == 'b')
        {
            State state = State();
            state.num = ++nodec;
            graph.back().b.push_back(nodec);
            graph.push_back(state);
        }
    }
    cout << "NFA" << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        cout << graph.at(i).num << "\t";
        for (int j = 0; j < graph.at(i).a.size(); j++)
            cout << graph.at(i).a.at(j) << " ";
        cout << "\t";
        for (int j = 0; j < graph.at(i).b.size(); j++)
            cout << graph.at(i).b.at(j) << " ";
        cout << endl;
    }

    set<vector<int>> visited;
    vector<vector<int>> onA;
    vector<vector<int>> onB;

    vector<int> start;
    start.push_back(0);
    visited.insert(start);

    for (int i = 0; i < visited.size(); i++)
    {
        vector<vector<int>> tempv(visited.begin(), visited.end());
        vector<int> tempA;
        vector<int> tempB;
        for (int j = 0; j < tempv.at(i).size(); j++)
        {
            int index = tempv.at(i).at(j);
            for (int k = 0; k < graph.at(index).a.size(); k++)
                tempA.push_back(graph.at(index).a.at(k));
            for (int k = 0; k < graph.at(index).b.size(); k++)
                tempB.push_back(graph.at(index).b.at(k));
        }
        onA.push_back(tempA);
        onB.push_back(tempB);
        visited.insert(tempA);
        visited.insert(tempB);
    }

    vector<vector<int>> tempv(visited.begin(), visited.end());
    for (int i = 0; i < tempv.size(); i++)
    {
        for (int j = 0; j < tempv.at(i).size(); j++)
            cout << tempv.at(i).at(j);
        cout << "\t";
        for (int j = 0; j < onA.at(i).size(); j++)
            cout << onA.at(i).at(j);
        cout << "\t";
        for (int j = 0; j < onB.at(i).size(); j++)
            cout << onB.at(i).at(j);
        cout << endl;
    }
}