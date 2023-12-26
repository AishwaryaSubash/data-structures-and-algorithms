//NFA/DFA FROM REGEX

#include <bits/stdc++.h>
using namespace std;
int nodecount = 0;

struct State
{
    int num;
    vector<int> a;
    vector<int> b;
};

int main()
{
    string regex;
    cout << "Enter Regex : ";
    getline(cin, regex);

    vector<State> graph;      // All NFA Graph
    graph.push_back(State()); // 0th/ start state
    
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
                i++; // counting while
            }
            if (regex[i + 1] == '*') // self loop
            {
                graph.back().num = nodecount; // naming the node
                for (int j = 0; j < ch.length(); j++)
                {
                    if (ch[j] == 'a')
                        graph.back().a.push_back(nodecount); // edge update
                    else if (ch[j] == 'b')
                        graph.back().b.push_back(nodecount); // edge update
                }
            }
            else // Next node hop
            {
                State state = State();
                state.num = ++nodecount;
                for (int j = 0; j < ch.length(); j++)
                {
                    if (ch[j] == 'a')
                        graph.back().a.push_back(nodecount); // edge update
                    else if (ch[j] == 'b')
                        graph.back().b.push_back(nodecount); // edge update
                }
                graph.push_back(state); // ! pushing here
            }
        }
        else if (regex[i] == 'a')
        {
            graph.back().a.push_back(++nodecount); //outward edge update
            State state = State();
            state.num = nodecount;
            graph.push_back(state);
        }
        else if (regex[i] == 'b')
        {
            graph.back().b.push_back(++nodecount); //outward edge update
            State state = State();
            state.num = nodecount;
            graph.push_back(state);
        }
    }
    cout << "\nNFA Transition Table : \n"
         << endl;
    cout << "State\tA\tB" << endl;
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

    // For DFA Conversion
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
        vector<vector<int>> tempvec(visited.begin(), visited.end());
        
        for (int j = 0; j < tempvec.at(i).size(); j++)
        {
            int index = tempvec.at(i).at(j);
            for (int k = 0; k < graph.at(index).a.size(); k++)
                tempA.push_back(graph.at(index).a.at(k));
            for (int k = 0; k < graph.at(index).b.size(); k++)
                tempB.push_back(graph.at(index).b.at(k));
        }
        onA.push_back(tempA);
        onB.push_back(tempB);

        // ! New states
        visited.insert(tempA);
        visited.insert(tempB);
    }
    cout << "\nDFA Transition Table : \n"
         << endl;
    cout << "\nState\ta\tb\n";
    vector<vector<int>> tempvec(visited.begin(), visited.end());
    for (int i = 0; i < tempvec.size(); i++)
    {
        for (int j = 0; j < tempvec.at(i).size(); j++)
            cout << tempvec.at(i).at(j);
        cout << "\t";
        for (int j = 0; j < onA.at(i).size(); j++)
            cout << onA.at(i).at(j);
        cout << "\t";
        for (int j = 0; j < onB.at(i).size(); j++)
            cout << onB.at(i).at(j);
        cout << endl;
    }
}
// (a|b)*abb
// abb(a|b)*
// (a|b)*abb(a|b)