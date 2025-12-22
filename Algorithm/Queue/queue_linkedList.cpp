#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

Node *createList(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void enqueue(int data)
{
    if (front == NULL)
    {
        front = createList(data);
        rear = front;
    }
    else
    {
        Node *temp = createList(data);
        rear->next = temp;
        rear = rear->next;
    }
}

void deQueue()
{
    if (front == NULL)
    {
        cout << "Queue Underflow";
    }
    else if (front == rear)
    {
        free(front);
        front = rear = NULL;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        free(temp);
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
    enqueue(10); //[10]
    enqueue(20); //[10,20]
    enqueue(30); //[10,20,30]
    deQueue();   //[20,30]
    Display(front);
}