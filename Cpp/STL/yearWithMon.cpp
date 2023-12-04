#include <bits/stdc++.h>
using namespace std;

int main()
{
    int year = 2022;
    int mon = 13;
    map<int, string> m = {
        {0, "Jan"},
        {1, "Feb"},
        {2, "Mar"},
        {3, "Apr"},
        {4, "May"},
        {5, "Jun"},
        {6, "Jul"},
        {7, "Aug"},
        {8, "Sept"},
        {9, "Oct"},
        {10, "Nov"},
        {11, "Dec"},
    };
    cout << "Year " << year + mon / 12 << endl;
    cout << "Month " << m[mon / 12];
}