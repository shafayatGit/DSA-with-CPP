#include <iostream>
using namespace std;

struct Node
{
    string name;
    int id;
    struct Node *next;
} *first;

void create(int A[], int n)
{

    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node)); // Or first = new Node;-> creating a new node
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
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

void display(struct Node *p)
{
    while (p != NULL)
    {
        if (p->data % 2 == 1)
        {
            cout << p->data << " ";
        }

        p = p->next;
    }
}

int add(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

// searching
struct Node *Search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

// deleting
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x = -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
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

// int Count(struct Node *p)
// {
//     if (p == 0)
//         return 0;
//     else
//     {
//         Count(p->next) + 1;
//     }
// }

int main()
{
    int A[] = {3, 2, 7, 9, 12, 17};
    create(A, 6);

    // we can also create like this
    //  first = new Node{10, nullptr};
    //  first->next = new Node{20, nullptr};
    //  first->next->next = new Node{30, nullptr};
    // Delete (first, 2);
    display(first);
    // int sum = add(first);
    // struct Node *keyFound = Search(first, 9);
    // cout << "Key Found: " << keyFound->data << endl;
    // cout << "Sum: " << sum;
}