#include <stdio.h>
#include <string.h>

// bool palin(char *l, char *r)
// {
//     while (l<r) {
//         if (*l++!=*r--) return false;
//     }
//     return true;
// }

int main()
{
    char s[] = "abca";
    char *left = s;
    char *right = s + strlen(s) - 1;

    while (left < right)
    {
        if (*left == *right)
        {
            ++left;
            --right;
        }
        else
        {
            // return palin(left+1, right) || palin(left, right-1);
        }
    }
}