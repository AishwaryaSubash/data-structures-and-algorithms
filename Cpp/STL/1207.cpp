#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int> &arr)
{
    map<int,int> m;
    for (int i=0 ; i<arr.size() ; i++) {
        m[arr[i]]++;
    }
    map<int,int>::iterator it = m.begin();
    while (it!=m.end()) {
        if (it->second == --it->second) 
            return false;
    }
    return true;
}

int main()
{
    vector<int> n = {1, 2, 2, 1, 1, 3};
    cout << uniqueOccurrences(n);
}