#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int maximum(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{ // 1 2 3 4 5
    int a[MAX];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    list<int> l;
    stack<int> s;
    // 11 11 10 10 10
    // 1 2 3 4 5
    // 5 3 2 4 1

    // * 0 0 0 0
    // * 0 0 * 0
    // * * 0 * 0
    // * * * * 0
    // * * * * *

    // 5 3 2 4 1
    // 1 2 3 4 5
    int max = 0;
    for (int i = 1; i <= maximum(a, n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i <= a[j])
            {
                sum++;
            }
            else if (i <= j + 1)
            {
                break;
            }
        }
        l.push_back(sum * i);
    }  
    cout << "\nOrder : ";
    for (auto const &i : l)
    {
        cout << i << " ";
    }
    l.sort();
    cout << "\nMax :" << l.back();
    return 0;
}
