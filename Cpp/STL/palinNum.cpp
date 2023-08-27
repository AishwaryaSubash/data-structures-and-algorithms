#include <bits/stdc++.h>
using namespace std;

// bool palin(int n)
// {
//     if (n < 0)
//     {
//         return false;
//     }
//     else if (n == 0)
//     {
//         return true;
//     }
//     else
//     {
//         long long int m = n;
//         long long int sum = 0;
//         long long int k = 1;
//         while (n > 0)
//         {
//             int digit = n % 10;
//             sum += digit * k;
//             k *= 10;
//             n = n / 10;
//         }
//         if (sum == m)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// }

bool palin(int n)
{
    if (n < 0)
        return false;
    else
    {
        int count = 0;
        int m = n, o = n;
        while (m != 0)
        {
            m = m / 10;
            count++;
        }
        int left = int(n / 10);
        int right = int(n % 10);
        int l = 0, r = count;
        cout << left << " " << right;
        // while (l < r)
        // {
        //     if (left == right)
        //     {
        //         left = int(m / 10);
        //         right = int(m % 10);
        //         m = int(m / 10);
        //         l++, r--;
        //         cout << m;
        //     }
        //     else
        //     {
        //         return false;
        //     }
        // }
    }
    return true;
}
int main()
{
    int num = 12123;
    // cout <<
    palin(num);
}