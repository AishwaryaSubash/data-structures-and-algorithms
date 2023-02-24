#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "n";
    cin >> n;
    n = n - 1;
    // cout<<"rows :";
    // cin>>n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = n - i; j <= n; j++)
        {
            cout << "*";
        }
        for (int j = i; j < n; j++)
        {
            cout << " ";
        }
        for (int j = n; j > i; j--)
        {
            cout << " ";
        }
        for (int j = n - i; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            cout << "*";
        }
        for (int j = n - i; j < n; j++)
        {
            cout << " ";
        }
        for (int j = n - i; j < n; j++)
        {
            cout << " ";
        }
        for (int j = n; j >= i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}

/*

*------*
**----**
***--***
********
********
***--***
**----**
*------*

*/
