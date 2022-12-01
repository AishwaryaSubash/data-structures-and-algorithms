#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt=1;
    cout<<"rows :";
    cin>>n;
    for (int i=1 ; i<n ; i++) {
        for (int j=1 ; j<=i ; j++) {
            cout<<cnt<<"  ";
            cnt++;
        }
        cout<<"\n";
    }
    return 0;
}