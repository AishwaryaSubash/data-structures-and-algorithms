#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    else
    {
        struct ListNode *slowPtr = head;
        struct ListNode *fastPtr = head;
        do
        {
            if (fastPtr == NULL || fastPtr->next == NULL || slowPtr == NULL || slowPtr->next == NULL)
                return false;
            // printf("%d %d\n", slowPtr->val, fastPtr->val);
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        } while (slowPtr != fastPtr);
    }
    return true;
}

int main()
{
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *head = node1;
    node1->val = 1;
    node2->val = 2;
    node3->val = 0;
    node4->val = -4;
    node1->next = node2;
    node2->next = NULL;
    node3->next = node4;
    node4->next = node2;

    printf("%d ", hasCycle(head));
}