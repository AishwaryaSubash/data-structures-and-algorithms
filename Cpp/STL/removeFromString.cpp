// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string num;
//     cin >> num;
//     int k;
//     cin >> k;
//     num.erase(0, 1);
//     num.erase(num.length() - 1, 1);
//     int min = 99999;
//     int ind = -1;
//     int i;
//     string sub;
//     string s;
//     for (i = 0; i < num.length() - k; i++)
//     {
//         sub = num.substr(i, k);
//         s = num;
//         s.erase(i, k);
//         if (stoi(s) < min)
//         {
//             min = stoi(sub);
//             ind = i;
//         }
//     }
//     // cout << sub << " " << ind;
//     // cout << num << " " << sub << endl;
//     cout << ind << " " << min << " ";
//     num.erase(ind, k);
//     // i -= k;
//     // cout << ind << " " << i << " " << max << endl;
//     cout << "\"" << num << "\"";
// }

// Akash's code
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mini = INT_MAX;
    string s;

    int k;
    cin >> s;
    cin >> k;
    s.erase(remove(s.begin(), s.end(), '"'), s.end());
    for (int i = 0; i < int(s.length()); i++)
    {
        string temp = s;
        if (i + k < int(s.length()))
        {
            temp.erase(temp.begin() + i, temp.begin() + i + k);
            int ok = atoi(temp.c_str());
            if (ok < mini)
            {
                mini = ok;
            }
        }
    }
    cout << '"' << mini << '"';
    return 0;
}
