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

ListNode *rotateRight(ListNode *head, int k)
{
    ListNode *first = head;
    ListNode *second = head;

    while (k > 0 && second != NULL)
    {
        second = second->next;
        k--;
    }
    while (second->next != NULL)
    {
        first = first->next;
        second = second->next;
    }

    ListNode *answer = first->next;
    first->next = NULL;
    second->next = head;
    return answer;
}

int main()
{
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *head = node1;
    // node1->val = 1;
    // node2->val = 2;
    // node3->val = 3;
    // node4->val = 4;
    // node5->val = 5;
    // node1->next = node2;
    // node2->next = node3;
    // node3->next = node4;
    // node4->next = node5;
    // node5->next = NULL;

    node1->val = 0;
    node2->val = 1;
    node3->val = 2;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    int k = 4;
    ListNode *head2 = rotateRight(head, k);

    while (head2 != NULL)
    {
        printf("%d ", head2->val);
        head2 = head2->next;
    }
}