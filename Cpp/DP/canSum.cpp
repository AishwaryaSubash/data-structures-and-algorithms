#include <bits/stdc++.h>
using namespace std;

bool canSum(int target, vector<int> numbers, map<int,bool> &m) {
    if (m.find(target) != m.end())
        return true;
    if (target==0) return true;
    for (int i=0 ; i<numbers.size() ; i++) {
        if (target-numbers.at(i)>=0) {
            if (canSum(target-numbers.at(i), numbers, m)){
                m[target-numbers.at(i)] = true;
                return m[target-numbers.at(i)];
            }
        }
    }
    m[target] = 0;
    return false;
}

int main() {
    int target = 7;
    vector<int> numbers = {5,4,3,7};
    map<int,bool> m;
    cout<<canSum(target, numbers, m)<<endl;
    // for (pair<int,bool>p: m) {
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
}


// MY SOLUTION
// bool canSum(int target, vector<int> numbers, map<int,int> &m) {
//     if (target==0) return true;
//     if (find(numbers.begin(), numbers.end(), target)!=numbers.end()) {
//         m[target] = 1;
//         return m[target];
//     }
//     for (int i=0 ; i<numbers.size() ; i++) {
//         if (target-numbers.at(i)>=0) {
//             if (m.find(target-numbers.at(i)) != m.end())
//                 return true;
//             else 
//                 return canSum(target-numbers.at(i), numbers, m);
//         }
//     }
//     return false;
// }