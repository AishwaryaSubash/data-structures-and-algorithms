#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> v;
    
    cout<<"Enter nums: ";
    int a;
    for (int i=0; i<5; i++) {
        cin>>a;
        v.push_back(a);
    }
    cout<<v.begin()<<v.end()<<endl;
    sort(v.begin(),v.end());
    // for (int i=0; i<5; i++) {
    //     int temp;
    //     for (int j=i ; j<5 ; j++) {
    //         if (v[i]>v[j]) {
    //             temp = v[i];
    //             v[i] = v[j];
    //             v[j] = temp;
    //         }
    //     }
    // }
    for (int i=0; i<5; i++) {
        cout<<" "<<v[i];
    }

}
