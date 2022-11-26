#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} * head;

void ins(int ind, int ele)
{
    struct node *ptr = new node;
    struct node *temp = head;
    ptr->data = ele;
    if (ptr == NULL)
        cout << "underflow" << endl;
    else
    {
        if (head == NULL)
        {
            head = ptr;
            ptr->next = NULL;
        }
        else
        {
            struct node *temp1 = NULL;
            for (int i = 0; i < ind; i++)
            {
                if (temp == NULL)
                    break;
                temp1 = temp;
                temp = temp->next;
            }
            if (temp != NULL)
            {
                temp1->next = ptr;
                ptr->next = temp;
            }
            else
            {
                cout << "No doja" << endl;
            }
        }
    }
}
void create(int ele)
{
    struct node *ptr = new node;
    struct node *temp = head;
    ptr->data = ele;
    if (ptr == NULL)
        cout << "underflow" << endl;
    else
    {
        if (head == NULL)
        {
            head = ptr;
            ptr->next = NULL;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = ptr;
            ptr->next = NULL;
        }
    }
}
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    int ele;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        create(ele);
    }
    display();
    ins(3, 70);
    display();
}
