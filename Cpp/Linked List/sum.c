#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head1, *head2, *head3;

void beginsert(int val, struct node* head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("overflow");
    }
    else
    {
        if (head==NULL){
            head = ptr;
            ptr->next=head;
        } else {
            temp=head;
            ptr->data = val;
            ptr->next = head;
            head = ptr;
        }
    }
}

void print(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node *));
    ptr = head;
    if (ptr == NULL)
    {
        printf("overflow");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int a = 8, b = 5;
    beginsert(a, head1);
    beginsert(7, head1);
    beginsert(8, head1);
    beginsert(b, head2);
    beginsert(4, head2);
    beginsert(5, head2);
    print(head1);
    printf("\n");
    print(head2);
    return 1;
}