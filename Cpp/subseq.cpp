#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin>>a;
    cin>>b;
    map<char, int> x;
    map<char, int> y;
    for (int i=0 ; i<a.length() ; i++) {
        for (int j=i ; j<b.length() ; j++) {
            if (a[i]==b[j]) {
                x.insert({a[i],i});
                y.insert({b[i],j});

            }
        }
    }
    int count=0;
    int len = (x.size()>y.size()) ? x.size() : y.size();
    for (int i=0 ; i<x.size() ; i++) {
        if (x[i]==y[i]) {
            count++;
        }
    }
    cout<<count<<" ";
}