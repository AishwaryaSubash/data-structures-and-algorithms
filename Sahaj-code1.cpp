#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin>>n>>t;
    vector<int>v(n);
    for (int i=0 ; i<n ; i++) {
        cin>>v.at(i);
    }
    
    int start=1;
    int next=1;
    int count=0;
    while(true) {
        next = v.at(next-1);
        count++;
        if (next==start || count==n) {
            cout<<"No";
            break;
        }
        if (next==t) {
            cout<<"Yes";
            break;
        }
    }
}