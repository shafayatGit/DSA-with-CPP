#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int arr[], int len)
{
    struct Node *t, *last;

    first = new Node;
    first->data = arr[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (int i = 1; i < len; i++)
    {
        t = new Node;
        t->data = arr[i];
        // t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void Insert(struct Node *p, int index, int data)
{
    if (index == 0)
    {
        struct Node *t = new Node;
        t->prev = NULL;
        t->data = data;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        struct Node *t = new Node;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->data = data;
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

void InsertLast(struct Node *p, int data)
{
    struct Node *t = new Node;
    t->data = data;
    t->next = NULL;
    while (p != NULL)
    {
        p = p->next;
    }
    t->prev = p;
    p = t->prev;
}

void Delete(struct Node *p, int index)
{
    if (index == 1)
    {

        first = first->next;
        delete p;
        if (first)
            first->prev = NULL;
    }
    else
    {

        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        delete p;
    }
}

int len(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 20};
    create(arr, 6);

    Insert(first, 0, 5);
    // Insert(first, 1, 5);
    // Insert(first, 2, 35);
    // InsertLast(first, 80);
    Delete(first, 1);
    Display(first);
}