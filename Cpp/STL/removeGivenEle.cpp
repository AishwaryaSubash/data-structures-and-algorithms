#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {3, 2, 2, 3};
    int val=3;
    for (int i=0 ; i<v.size() ; i++) {
        if (v.at(i)==val) {
            v.erase(v.begin()+i);
        }
    }
    for (int i=0 ; i<v.size() ; i++) {
        cout<<v.at(i)<<" ";
    }
}