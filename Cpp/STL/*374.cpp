#include <bits/stdc++.h>
using namespace std;

int guessNumber(int n)
{
    int pick = (1+n)/2;
    if (n==pick) {
        
        return n;
    }
}

int main()
{
    int n = 10;
    cout << guessNumber(n);
}