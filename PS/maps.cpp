#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> m = {
        {"A", 10},
        {"B", 20},
        {"C", 30}};

    // for (auto &itr : m) {
    //     cout<<itr.first<<"\t"<<itr.second<<endl;
    // }
    cout<<m["A"]<<"\t"<<m["B"];
    cout<<m.size();
    m.insert(pair<string, int>("D", 40));

    return 0;
}