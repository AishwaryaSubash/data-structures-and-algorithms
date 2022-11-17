#include <bits/stdc++.h>
#include <string.h>
using namespace std;
struct node
{
    int rollno;
    string name;
    char gender;
    struct node *next;
} * head, *temp;
void printList()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->rollno << " , "  << ptr->name << " , " << ptr->gender << endl;
        ptr = ptr->next;
    }
}
void insert(string name, int roll, char gender)
{
    struct node *ptr = new node;
    if (ptr == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        ptr->rollno = roll;
        ptr->name = name;
        ptr->gender = gender;
        ptr->next = NULL;
        if (head == NULL)
        {
            head = ptr;
            printf("\nNode inserted");
        }
        else // * Insert based on rollnum
        {
            temp = head;
            while (temp != NULL)
            {
                if (temp->rollno == ptr->rollno) // * No dups
                {
                    cout << "Roll num already exists";
                    free(ptr);
                    break;
                }
                else if (head->rollno > ptr->rollno)
                {
                    ptr->next = head;
                    head = ptr;
                    break;
                }
                else if (temp->next != NULL)
                {
                    if (temp->next->rollno > ptr->rollno)
                    {
                        ptr->next = temp->next;
                        temp->next = ptr;
                        break;
                    }
                }
                else
                {
                    cout << temp->rollno << " ";
                    temp->next = ptr;
                    ptr->next = NULL;
                    break;
                }
                temp = temp->next;
            }
        }
    }
}
void deletion(string name)
{
    temp = head;
    struct node *prev = head;
    int flag = 0;
    if (temp == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else
    {
        while (temp != NULL)
        {
            const char *str1 = temp->name.c_str();
            const char *str2 = name.c_str();
            // cout << str1 <<" "<< str2<<endl;
            if (strcmp(str1, str2) == 0)
            {
                if (temp == head)
                {
                    head = temp->next;
                    flag += 1;
                    free(temp);
                }
                else
                {
                    flag += 1;
                    prev->next = temp->next;
                    free(temp);
                    temp = NULL;
                }
            }
            if (temp != NULL)
            {
                prev = temp;
            }
            temp = prev->next;
        }
        if (flag == 0)
        {
            cout << "Name doesnot exist" << endl;
        }
    }
}

void search(string name) {
    
}


int main()
{
    string names[] = {"aish", "karthi", "akash", "X", "g", "hhh", "ff", "x", "aish", "aish"};
    int rolls[] = {7, 42, 8, 3, 23, 7, 3, 0, 5, 1};
    char genders[] = {'f', 'm', 'm', 'f', 'm', 'f', 'g', 'f', 'f', 'f'};
    for (int i = 0; i < 10; i++)
    {
        insert(names[i], rolls[i], genders[i]);
        cout << "\n";
    }
    printList();
    string n;
    cout << "\nEnter name: ";
    cin >> n;
    deletion(n);
    printList();

    return 0;
}
