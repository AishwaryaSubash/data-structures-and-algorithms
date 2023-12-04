#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *ptr = head;
    struct ListNode *rhead = NULL;
    while (ptr != NULL)
    {
        ListNode *ptr2 = new ListNode();
        ptr2->next = rhead;
        ptr2->val = ptr->val;
        ptr = ptr->next;
        rhead = ptr2;
    }
    return rhead;
}

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
    node4->val = 4;
    node5->val = 5;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    struct ListNode *head2 = reverseList(head);
    while (head2 != NULL)
    {
        printf("%d ", head2->val);
        head2 = head2->next;
    }
}