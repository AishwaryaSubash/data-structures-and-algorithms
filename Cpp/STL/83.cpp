#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// O(n) time; O(1) space; 3 ms
ListNode *removeDuplicates(ListNode *head)
{
    if (head != NULL && head->next != NULL)
    {
        struct ListNode *ptr = head;
        struct ListNode *ptr2 = head->next;
        while (ptr2 != NULL)
        {
            if (ptr->val == ptr2->val)
            {
                ptr->next = ptr2->next;
                ptr2 = ptr->next;
            }
            else
            {
                ptr = ptr->next;
                ptr2 = ptr2->next;
            }
        }
    }
    return head;
}

// O(n) time; O(1) space; 0 ms - USING SINGLE POINTER
// ListNode *deleteDuplicates(ListNode *head)
// {
//     ListNode *temp = head;

//     while (temp && temp->next)
//     {
//         if (temp->val == temp->next->val)
//             temp->next = temp->next->next;
//         else
//             temp = temp->next;
//     }
//     return head;
// }

int main()
{
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *head = node1;
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 3;
    node5->val = 3;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    ListNode *head2 = removeDuplicates(head);

    while (head2 != NULL)
    {
        printf("%d ", head2->val);
        head2 = head2->next;
    }
}