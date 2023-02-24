#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    cin>>num;
    vector<int>factors;
    for (int i=1 ; i<=(num/2) ; i++) {
        if (num%i==0) {
            factors.push_back(i);
        }
    }
    int sum=0;
    for (int n: factors) {
        sum+=n;
    }
    if (sum==num){
        cout<<true;
    } else {
        cout<<false;
    }
}