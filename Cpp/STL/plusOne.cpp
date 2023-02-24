#include <bits/stdc++.h>
using namespace std;

void plusOne(vector<int> digits)
{
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits.at(i) == 9)
        {
            digits.at(i) = 0;
            if (i == 0)
            {
                digits.insert(digits.begin(), 1);
            }
        }
        else
        {
            digits.at(i) += 1;
            break;
        }
    }

    for (int i : digits)
    {
        cout << i;
    }
}

int main()
{
    vector<int> digits = {1, 2, 9};
    plusOne(digits);
}