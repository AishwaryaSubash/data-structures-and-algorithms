// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;
//     cin >> s;
//     vector<char> v = {'(', '{', '['};
//     stack<char> stk;
//     char b;
//     int flag = 0;
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (find(v.begin(), v.end(), s.at(i)) != v.end())
//         {
//             stk.push(s.at(i));
//         }
//         else
//         {
//             if (stk.size() == 0)
//             {
//                 flag = 1;
//             }
//             else
//             {
//                 b = stk.top();
//                 if (s.at(i) == ')')
//                 {
//                     if (b == '(')
//                     {
//                         stk.pop();
//                         // flag = 1;
//                     }
//                     else
//                     {
//                         flag = 1;
//                         break;
//                     }
//                 }
//                 if (s.at(i) == '}')
//                 {
//                     if (b == '{')
//                     {
//                         stk.pop();
//                         // flag = 1;
//                     }
//                     else
//                     {
//                         flag = 1;
//                         break;
//                     }
//                 }
//                 if (s.at(i) == ']')
//                 {
//                     if (b == '[')
//                     {
//                         stk.pop();
//                         // flag = 1;
//                     }
//                     else
//                     {
//                         flag = 1;
//                         break;
//                     }
//                 }
//             }
//         }
//         if (flag == 1)
//         {
//             cout << "false";
//             // return 1;
//         }
//     }
//     if (flag == 0 && stk.size() == 0)
//     {
//         cout << "true";
//         return 0;
//     }
//     else
//     {
//         cout << "false";
//         // return 1;
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> vec(n);
    for (int z = 0; z < n; z++)
    {
        string s;
        cin >> s;
        vec.push_back(s);
    }

    for (int z = 0; z < n; z++)
    {
        string s = vec.at(z);
        // cin >> s;
        vector<char> v = {'(', '{', '['};
        stack<char> stk;
        char b;
        int flag = 0;
        for (long unsigned int i = 0; i < s.length(); i++)
        {
            if (find(v.begin(), v.end(), s.at(i)) != v.end())
            {
                stk.push(s.at(i));
            }
            else
            {
                if (stk.size() == 0)
                {
                    flag = 1;
                }
                else
                {
                    b = stk.top();
                    if (s.at(i) == ')')
                    {
                        if (b == '(')
                        {
                            stk.pop();
                            // flag = 1;
                        }
                        else
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (s.at(i) == '}')
                    {
                        if (b == '{')
                        {
                            stk.pop();
                            // flag = 1;
                        }
                        else
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (s.at(i) == ']')
                    {
                        if (b == '[')
                        {
                            stk.pop();
                            // flag = 1;
                        }
                        else
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if (flag == 1)
            {
                cout << "NO";
                // return 1;
            }
        }
        if (flag == 0 && stk.size() == 0)
        {
            cout << "YES";
            return 0;
        }
        else
        {
            cout << "NO";
            // return 1;
        }
    }
}
