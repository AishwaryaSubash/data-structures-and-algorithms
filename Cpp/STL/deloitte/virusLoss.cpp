#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, n;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
        cin >> v[i];
    cin >> n;
    for (auto i : v)
        cout << i << " " << (i >> n) << endl;
        
    /*
        left-shifting an integer “a” with an integer “b” denoted as '(a<<b)' is equivalent to multiplying a with 2^b
        right-shifting an integer “a” with an integer “b” denoted as '(a>>b)' is equivalent to dividing a with 2^b
    */
}