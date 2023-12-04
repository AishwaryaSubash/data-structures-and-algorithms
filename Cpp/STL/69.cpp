#include <bits/stdc++.h>
using namespace std;

// 69. Sqrt(x)

int mySqrt(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    for (int i = 1; i <= x / 2; i++)
    {
        if (i * i == x)
        {
            return i;
        }
        else if (i * i > x)
        {
            return i - 1;
        }
    }
    return 0;
}

// O(n log n)
// int mySqrt(int x)
// {
//     if (x == 0)
//         return x;
//     int first = 1, last = x;
//     while (first <= last)
//     {
//         int mid = first + (last - first) / 2;
//         // mid * mid == x gives runtime error
//         if (mid == x / mid)
//             return mid;
//         else if (mid > x / mid)
//         {
//             last = mid - 1;
//         }
//         else
//         {
//             first = mid + 1;
//         }
//     }
//     return last;
// }

int main()
{
    cout << mySqrt(5);
}