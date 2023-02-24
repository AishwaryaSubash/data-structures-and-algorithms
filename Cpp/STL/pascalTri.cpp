#include <bits/stdc++.h>
using namespace std;

void generate(int numRows)
{
    vector<vector<int>> nums;
    vector<int> l;
    for (int i = 0; i <= numRows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                l.push_back(1);
            }
            else
            {
                l.push_back(nums.at(i - 1).at(j) + nums.at(i - 1).at(j - 1));
            }
        }
        nums.push_back(l);
        l.clear();
    }
    for (vector<int> i : nums)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    int num = 4;
    generate(num);
}

// i-1, j
// i-1, j-1
