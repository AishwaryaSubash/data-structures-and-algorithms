#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

// O(n) time; O(n) space
ListNode *swapPairs(ListNode *head)
{
    bool swap = true;
    if (head == NULL)
        return head;
    struct ListNode *ptr = head;
    while (ptr->next != NULL)
    {
        if (swap)
        {
            int temp = ptr->val;
            ptr->val = ptr->next->val;
            ptr->next->val = temp;
            swap = false;
        }
        else
        {
            swap = true;
        }
        ptr = ptr->next;
    }
    return head;
}

// O(n) time; O(1) space

// ListNode *swapPairs(ListNode *head)
// {
//     if (!head || !head->next)
//     {
//         return head;
//     }
//     ListNode *p = head, *q = head->next;
//     while (true)
//     {
//         swap(p->val, q->val);
//         if (!(q->next && q->next->next))
//             break;
//         p = p->next->next;
//         q = q->next->next;
//     }
//     return head;
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
    node3->val = 3;
    node4->val = 4;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    ListNode *head2 = swapPairs(head);

    while (head2 != NULL)
    {
        printf("%d ", head2->val);
        head2 = head2->next;
    }
}