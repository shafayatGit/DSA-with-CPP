#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void Insert(struct Node *p, int index, int x)
{
    struct Node *t = new Node;
    t->data = x;
    t->next = NULL;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1 && p != NULL; i++)
            p = p->next;

        p->next = t->next;
        p->next = t;
    }
}
int Count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}
void ReverseLinks(struct Node *p)
{
    struct Node *q = NULL;
    struct Node *r = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
int main()
{
    // cout<<"Running";
    Insert(first, 0, 3);
    Insert(first, 1, 10);
    Insert(first, 2, 5);
    Insert(first, 3, 16);
    ReverseLinks(first);
    Display(first);
}