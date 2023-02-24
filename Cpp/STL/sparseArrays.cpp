#include <bits/stdc++.h>
#include <string>
#include <map>
#include <vector>
using namespace std;

void func(vector<string> stringList, vector<string> queries)
{
    vector <int> v;
    for (string q : queries)
    {
        int count = 0;   
        for (string s : stringList)
        {
            if (s.compare(q)==0) {
                count++;
            }         
        }
        v.push_back(count);
        
    }
    for (int i=0 ; i<v.size() ; i++) {
        cout<<v.at(i)<<" ";
    }
    
}

int main()
{
    vector<string> stringList = {"aba", "baba", "aba", "xzxb"};
    vector<string> queries = {"aba", "xzxb", "ab"};
    func(stringList, queries);
}