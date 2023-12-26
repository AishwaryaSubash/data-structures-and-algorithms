//NFA/DFA TO DFA/NFA
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
    vector<State> graph;
    int nodec;
    cout << "Enter nodecount ";
    cin >> nodec;
    for (int i = 0; i < nodec; i++)
    {
        State state = State();
        state.num = i;
        int ac = 0, bc = 0;
        cout << "For node " << i << endl;
        cout << "A trans ";
        cin >> ac;
        cout << "B trans ";
        cin >> bc;
        if (ac > 0)
        {
            cout << "Enter A trans ";
            for (int j = 0; j < ac; j++)
            {
                int to;
                cin >> to;
                if (to != -1)
                    state.a.push_back(to);
            }
        }
        if (bc > 0)
        {
            cout << "Enter B trans ";
            for (int j = 0; j < bc; j++)
            {
                int to;
                cin >> to;
                if (to != -1)
                    state.b.push_back(to);
            }
        }
        graph.push_back(state);
    }
    set<vector<int>> visited;
    vector<vector<int>> onA;
    vector<vector<int>> onB;
    vector<int> start;
    start.push_back(0);
    visited.insert(start);
    for (int i = 0; i < visited.size(); i++)
    {
        vector<int> tempA;
        vector<int> tempB;
        vector<vector<int>> tempv(visited.begin(),
                                  visited.end());
        for (int j = 0; j < tempv.at(i).size(); j++)
        {
            int index = tempv.at(i).at(j);
            for (int k = 0; k < graph.at(index).a.size();
                 k++)
                tempA.push_back(graph.at(index).a.at(k));
            for (int k = 0; k < graph.at(index).b.size();
                 k++)
                tempB.push_back(graph.at(index).b.at(k));
        }
        onA.push_back(tempA);
        onB.push_back(tempB);
        visited.insert(tempA);
        visited.insert(tempB);
    }
    cout << "DFA transition table" << endl;
    vector<vector<int>> tempv(visited.begin(),
                              visited.end());
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
