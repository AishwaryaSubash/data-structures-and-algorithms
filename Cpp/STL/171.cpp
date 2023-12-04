#include <bits/stdc++.h>
using namespace std;

// 171. Excel Sheet Column Number

int titleToNumber(string columnTitle)
{
    // O(n)
    int num = 0;
    int p = 0;
    for (int i = columnTitle.length() - 1; i >= 0; i--)
    {
        int ascii = columnTitle.at(i) - 'A' + 1;
        num += ascii * pow(26, p++);
    }
    return num;

    // O(n)
    // int result = 0;
    // for (char c : columnTitle)
    // {
    //     int d = c - 'A' + 1;
    //     result = result * 26 + d;
    // }
    // return result;
}

int main()
{
    string columnTitle = "BCM";
    cout << titleToNumber(columnTitle);
}
