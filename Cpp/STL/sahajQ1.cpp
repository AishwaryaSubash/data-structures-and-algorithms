#include <bits/stdc++.h>
using namespace std;

int main()
{
    int target;
    int n;
    cout << "n: ";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v.at(i);
    }
    cout << "t: ";
    cin >> target;

    int curr = 1;
    int count = 0;
    while (curr != target)
    {
        curr = v.at(curr - 1);
        if (curr == target)
        {
            cout << true;
            break;
        }
        if (count >= n)
        {
            cout << false;
            break;
        }
        count++;
    }
    cout << count;
    return 0;
}

// 1 2 3 4 5
// 4 3 1 5 2
// end 3 => true

// 1 2 3 4 5
// 4 3 2 5 1
// end 3 => false

// 1. max nodes
// 2. longest path