#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[5] = {1, 2, 3, 4, 5};
    int max = -1;
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int c = 0;
            if (a[i] <= a[j])
            {
                c++;
            }
            int smt = a[i] * c;
            if (max < smt)
            {
                max = smt;
            }
        }
    }
    printf("%d",max);
    return 0;
    
}
