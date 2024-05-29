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

ListNode* middleNode(ListNode* head) {
    if (head == NULL)
        return head;

    struct ListNode* ptr = head;
    int count=0;
    while (ptr!=NULL) {
        count++;
        ptr = ptr->next;
    }
    int middleInd = int(count/2)+1;
    ptr = head;
    while (middleInd!=1) {
        middleInd--;
        ptr = ptr->next;
    }
    ListNode *midNode = ptr;
    return midNode;
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

    ListNode *head2 = middleNode(head);

    while (head2 != NULL)
    {
        printf("%d ", head2->val);
        head2 = head2->next;
    }
}