#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

Node *
createList(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void push(int data)
{
    if (top == NULL)
    {
        top = createList(data);
    }
    else
    {
        Node *temp = createList(data);
        temp->next = top;
        top = temp;
    }
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow";
    }

    else
    {
        Node *temp = top;
        top = top->next;
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
    push(10); //[10]
    push(20); //[20,10]
    push(30); //[30,20,10];
    pop();    //[20,10]
    pop();    
    pop();    
    pop();    
    Display(top);
}