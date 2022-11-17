#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[5] = {1,2,3,4,5};
    int max = -1;
    for (int i = 0; i < 5; i++)
    {
        int c = 0;
        for (int j = i; j < 4; j++)
        {
            if (a[j] <= a[j+1])
            {
                c++;
            }
            cout << c << " ";
        }
        int smt = a[i] * c;
        if (max < smt)
        {
            max = smt;
        }
    }
    printf("\n%d\n", max);
    return 0;
}
