#include <iostream>
using namespace std;

struct Node
{
    char data;
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

// Insert
void Insert(struct Node *p, int index, char x)
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

// Deletion
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1;

    if (index == 1)
    {
        q = first;
        first = first->next;
        x = q->data;
        delete q;
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

// Count
int Count(struct Node *p)
{
    if (p == 0)
        return 0;
    else
    {
        return Count(p->next) + 1;
    }
}

int main()
{
    // in the insertion i have to maintain the index serialization or it will be exceed the index
    Insert(first, 0, 'A');
    Insert(first, 1, 'C');
    Insert(first, 2, 'D');
    Insert(first, 3, 'D');
    Insert(first, 0, 'Z');
    Insert(first, Count(first), 'L');
    Delete(first, 1);
    Display(first);
}
