#include <stdio.h>
#include <stdlib.h>

// 142. Linked List Cycle II

struct ListNode
{
    int val;
    struct ListNode *next;
};

ListNode *hasCycle(ListNode *head)
{
    struct ListNode *slowPtr = head;
    struct ListNode *fastPtr = head;
    while (fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            slowPtr = head;
            while (slowPtr != fastPtr)
            {
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next;
            }
            return slowPtr;
        }
    }
    return nullptr;
}

int main()
{
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *head = node1;
    node1->val = 5;
    node2->val = 0;
    node3->val = 7;
    node4->val = 6;
    node5->val = 8;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node2;

    ListNode *head2 = hasCycle(head);
    int count = 3;
    while (head2 != NULL)
    {
        printf("%d ", head2->val);
        head2 = head2->next;
        count--;
        if (count == 0)
            break;
    }
}