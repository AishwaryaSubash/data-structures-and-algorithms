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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    struct ListNode *ptr1 = list1;
    struct ListNode *ptr2 = list2;
    struct ListNode *ptr3 = NULL;
    if (ptr1->val > ptr2->val) {
        ptr3->val = ptr1->val;
        ptr1 = ptr1->next;
    } else {
        ptr3->val = ptr2->val;
        ptr2 = ptr2->next;
    }
    struct ListNode *head3 = ptr3;

    while (ptr1!=NULL && ptr2!=NULL) {
        struct ListNode *newNode=NULL;
        if (ptr1->val < ptr2->val) {
            newNode->val = ptr1->val;
        } else {
            newNode->val = ptr2->val;
        }
        newNode->next = NULL;
        ptr3 = newNode; 
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if (ptr1 != NULL) {
        ptr3->next = ptr1;
    } else {
        ptr3->next = ptr2;
    }
    return head3;
}

int main()
{
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node5 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *node6 = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *head1 = node1;
    ListNode *head2 = node4;
    node1->val = 1;
    node2->val = 2;
    node3->val = 3;
    node4->val = 1;
    node5->val = 3;
    node6->val = 4;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    ListNode *head3 = mergeTwoLists(head1, head2);

    while (head3 != NULL)
    {
        printf("%d ", head3->val);
        head3 = head3->next;
    }
}