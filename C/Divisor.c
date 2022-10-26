#include <stdio.h>

long signed int divide(long signed int dividend, long signed int divisor)
{
    int sign = 0;
    if (dividend < 0 && divisor < 0)
    {
        sign = 0;
        dividend = -dividend;
        divisor = -divisor;
    }
    else if (dividend < 0)
    {
        dividend = -dividend;
        sign = 1;
    }
    else if (divisor < 0)
    {
        divisor = -divisor;
        sign = 1;
    }
    long signed int dc = dividend;
    long signed int q = 0;
    while (dc >= divisor)
    {
        dc -= divisor;
        q++;
    }
    if (sign == 1 )
    {
        q = -q;
    }
    return q;
}

int main()
{
    printf("%ld", divide(-2147483648,-1));
}