#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;

Node *
createNode(int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void Insert(int data)
{
    if (first == NULL)
    {
        first = createNode(data);
        last = first;
    }
    // this always inserts last
    else
    {
        Node *temp = createNode(data);
        last->next = temp;
        last = last->next;
    }
}
void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    Insert(10);
    Insert(20);
    Insert(30);
    Display(first);
}