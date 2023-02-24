#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int main()
{
    int n = 4;
    int p[] = {4, 6, 7, 4};
    int d[] = {6, 5, 3, 5};
    petrolPump a[n * 2];

    for (int i; i < n; i++)
    {
        a->petrol = p[i];
        a->distance = d[i];
        cout << a->petrol << " " << a->distance << endl;
    }
}