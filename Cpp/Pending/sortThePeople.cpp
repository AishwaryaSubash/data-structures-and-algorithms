#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> names = {"IEO", "Sgizfdfrims", "QTASHKQ", "Vk", "RPJOFYZUBFSIYp", "EPCFFt", "VOYGWWNCf", "WSpmqvb"};
    vector<int> heights = {17233, 32521, 14087, 42738, 46669, 65662, 43204, 8224};
    for (int i = 0; i < heights.size(); i++)
    {
        for (int j = i; j < heights.size(); j++)
        {
            if (heights.at(i) < heights.at(j))
            {
                string temp = names.at(i);
                names.at(i) = names.at(j);
                names.at(j) = temp;
                int tmp = heights.at(i);
                heights.at(i) = heights.at(j);
                heights.at(j) = tmp;
            }
        }
    }
    for (int i = 0; i < heights.size(); i++)
    {
        cout << heights.at(i) << " " << names.at(i) << endl;
    }
}