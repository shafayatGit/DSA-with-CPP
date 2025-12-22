#include <iostream>
using namespace std;

int Queue[4];
int front = -1;
int rear = -1;

void enqueue(int data)
{

    if (front == -1)
    {
        front = rear = 0;
        Queue[front] = data;
    }
    else
    {
        int dummy_r = (rear + 1) % 4;
        if (dummy_r == front)
        {
            cout << "Queue Overflow";
        }
        else
        {
            rear = dummy_r;
            Queue[rear] = data;
        }
    }
}

void dequeue()
{
    if (front == -1)
    {
        cout << "queue underflow";
    }
    else if (front == rear)
    {
        cout << "Deleted: " << Queue[front];
        Queue[front] = 0;
        front = rear = -1;
    }
    else
    {
        cout << "Deleted:" << Queue[front];
        Queue[front] = 0;
        front = (front + 1) % 4;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
}