#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
    // ListNode() : val(0), next(nullptr) {}
    // ListNode(int x) : val(x), next(nullptr) {}
    // ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// PROBLEM - CONSECUTIVE TWOs
ListNode *removeElements(ListNode *head, int val)
{
    ListNode *ptr = head;
    if (head == NULL)
        return head;
    if (ptr->val == val)
    {
        head = ptr->next;
        ptr = head;
    }
    while (ptr->next != NULL)
    {
        if (ptr->next->val == val)
        {
            if (ptr->next->next != NULL)
                ptr->next = ptr->next->next;
            else
                ptr->next = NULL;
        }
        ptr = ptr->next;
    }

    return head;
}

int main()
{
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *head = node1;
    node1->val = 2;
    node2->val = 1;
    node3->val = 3;
    node4->val = 2;
    node5->val = 1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    int val = 2;
    ListNode *head2 = removeElements(head, val);

    while (head2 != NULL)
    {
        printf("%d ", head2->val);
        head2 = head2->next;
    }
}