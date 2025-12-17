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

void Insert(struct Node *p, int index, char x)
{
    struct Node *t = new Node;
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            t->next = p->next;
            p->next = t;
    }
}

int main()
{
    Insert(first, 0, 'A'); 
    Insert(first, 1, 'B');
    Insert(first, 2, 'D');
    Insert(first, 2, 'C');
    Display(first);
}
