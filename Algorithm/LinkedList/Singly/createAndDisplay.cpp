#include <iostream>
using namespace std;

struct Node
{
    int data;
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

void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
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

int main()
{
    int A[] = {3, 5, 7, 9};
    create(A, 4);

    // we can also create like this
    //  first = new Node{10, nullptr};
    //  first->next = new Node{20, nullptr};
    //  first->next->next = new Node{30, nullptr};

    display(first);
    int sum = add(first);
    struct Node *keyFound = Search(first, 9);
    cout << "Key Found: " << keyFound->data << endl;
    cout << "Sum: " << sum;
}