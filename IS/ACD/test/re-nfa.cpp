#include <bits/stdc++.h>
using namespace std;

struct State
{
    int num;
    vector<int> a;
    vector<int> b;
};

int main()
{
    string regex;
    getline(cin, regex);
    vector<State> graph;
    int nodec = 0;
    graph.push_back(State());

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
                for (int j = 0; j < ch.length(); j++)
                {
                    if (ch[j] == 'a')
                        graph.back().a.push_back(nodec);
                    if (ch[j] == 'b')
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

    cout << "\nNFA" << endl;
    cout << "State\ta\tb\n";
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

    set<vector<int>> visit;
    vector<vector<int>> onA;
    vector<vector<int>> onB;

    vector<int> start;
    start.push_back(0);
    visit.insert(start);

    for (int i = 0; i < visit.size(); i++)
    {
        vector<vector<int>> temp(visit.begin(), visit.end());
        vector<int> tempA;
        vector<int> tempB;
        for (int j = 0; j < temp.at(i).size(); j++)
        {
            int index = temp.at(i).at(j);
            for (int k = 0; k < graph.at(index).a.size(); k++)
                tempA.push_back(graph.at(index).a.at(k));
            for (int k = 0; k < graph.at(index).b.size(); k++)
                tempB.push_back(graph.at(index).b.at(k));
        }
        onA.push_back(tempA);
        onB.push_back(tempB);
        visit.insert(tempA);
        visit.insert(tempB);
    }

    cout << "\nDFA\n";
    cout << "State\ta\tb\n";

    vector<vector<int>> temp(visit.begin(), visit.end());
    for (int i = 0; i < temp.size(); i++)
    {
        for (int j = 0; j < temp.at(i).size(); j++)
            cout << temp.at(i).at(j);
        cout << "\t";
        for (int j = 0; j < onA.at(i).size(); j++)
            cout << onA.at(i).at(j);
        cout << "\t";
        for (int j = 0; j < onB.at(i).size(); j++)
            cout << onB.at(i).at(j);
        cout << "\n";
    }

    return 0;
}