#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head;

void Create(int arr[], int n)
{

    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node)); // Or head = new Node;-> creating a new node
    head->data = arr[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
}

void Insert(int pos, int x)
{
    struct Node *p, *t;
    t = new Node;
    t->data = x;
    if (pos == 0)
    {
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            p = head;
            while (p != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        p = head;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    // int arr[] = {10, 20, 30, 4};
    // Create(arr, 4);
    Insert(0,3);
    Insert(1,5);
    Display(head);
}