#include <bits/stdc++.h>
using namespace std;

// 234. Palindrome Linked List
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool isPalindrome(ListNode *head)
{
    struct ListNode *ptr = head;
    if (head == NULL)
    {
        return false;
    }
    else
    {
        stack<int> s;
        while (ptr != NULL)
        {
            s.push(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (!s.empty())
        {
            int i = s.top();
            if (ptr->val != i)
            {
                return false;
            }
            ptr = ptr->next;
            s.pop();
        }
    }
    return true;
}

// bool isPalindrome(ListNode *head)
// {
//     if (head == NULL || head->next == NULL)
//     {
//         return false;
//     }
//     else
//     {
//         ListNode *ptr = head;
//         ListNode *rhead = NULL;

//         while (ptr != NULL)
//         {
//             ListNode *temp = new ListNode(ptr->val);
//             temp->next = rhead;
//             rhead = temp;
//             ptr = ptr->next;
//         }
//         while (head && rhead)
//         {
//             if (head->val != rhead->val)
//                 return false;
//             rhead = rhead->next;
//             head = head->next;
//         }
//     }
//     return true;
// }

int main()
{
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *head = node1;
    node1->val = 1;
    node2->val = 2;
    node3->val = 2;
    node4->val = 1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    cout << isPalindrome(head);
}