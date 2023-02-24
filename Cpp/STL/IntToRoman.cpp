#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, string> roman = {{1, "I"},
                              {4, "IV"}};
    for (auto itr = roman.begin(); itr != roman.end(); ++itr)
    {
        cout << itr->first << '\t' << itr->second << '\n';
    }
}
