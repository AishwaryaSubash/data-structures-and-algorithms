#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Binary to Decimal Conversion Using Doubling Method
    string s = "101101";
    int num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        string t = "";
        t += s[i];
        int dig = stoi(t);
        num = (num * 2) + dig;
        // cout << num << endl;
    }
    cout << num;

    // * In a Linked List Approach (LeetCode)
    // int getDecimalValue(ListNode * head)
    // {
    //     int num = 0;
    //     while (head != NULL)
    //     {
    //         num = (num * 2) + head->val;
    //         head = head->next;
    //     }
    //     return num;
    // }
}