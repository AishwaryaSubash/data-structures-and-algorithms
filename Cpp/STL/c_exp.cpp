
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<*(*a + **a/2)+3;

    return 0;
}

