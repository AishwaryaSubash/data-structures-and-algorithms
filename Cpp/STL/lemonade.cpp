#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> bills = {5, 5, 5, 10, 20};
    int sum = 0;
    int change = 0;
    int c5 = 0, c10 = 0, c20 = 0;

    for (int i = 0; i < bills.size(); i++)
    {
        if (bills.at(i) == 5)
        {
            c5++;
            // sum += 5;
        }
        if (bills.at(i) == 10)
        {
            c10++;
            if (c5 >= 1)
            {
                c5--;
            }
            else
            {
                cout << false;
                break;
            }
        }
        if (bills.at(i) == 20)
        {
            c20++;
            if (c10 >= 1 && c5 >= 1)
            {
                c5--;
                c10--;
            }
            else if (c5 >= 3)

            {
                c5 -= 3;
            }
            else
            {
                cout << false;
                break;
            }
            // sum += 5;
            // change += 15;
        }
    }
    cout << true;
}
