// #include <stdio.h>
// #include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int countDigit(int num, int digit)
{
    int count = 0;

    while (num != 0)
    {
        int lastDigit = num % 10;
        if (lastDigit == digit)
        {
            count++;
        }
        num /= 10;
    }

    return count;
}

int main()
{
    int start = 1, end = 100, digit = 1;
    // get input here
    int numberOfDigits = 0;
    for (int i = start; i <= end; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
            numberOfDigits += countDigit(i, digit);
        }
    }
    cout << endl
         << numberOfDigits;
}