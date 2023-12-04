#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> details = {"7868190130M7522", "5303914400F9211", "9273338290F4010"};
    int count = 0;
    for (int i = 0; i < details.size(); i++)
    {
        string age = details.at(i).substr(11, 2);
        if (stoi(age) > 60)
            count++;
    }
    cout << count;
}