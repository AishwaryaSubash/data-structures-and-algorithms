#include <bits/stdc++.h>
using namespace std;

// 190. Reverse Bits

uint32_t reverseBits(uint32_t n)
{
    int i=0;
    int num=0;
    while (n>0) {
        num+= (n%2)*(pow(2,i));
        i++;
    }
    return n;
}

int main()
{
    uint32_t n = 00000010100101000001111010011100;
    n= reverseBits(n);
}