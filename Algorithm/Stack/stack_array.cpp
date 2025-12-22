#include <iostream>
using namespace std;
#define Size 4
int Stack[Size];
int top = -1;

void push(int data)
{
    if (top == -1)
    {
        top = 0;
        Stack[top] = data;
    }
    else if (top == Size - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top = top + 1;
        Stack[top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Stack[top] = 0;
        top = top - 1;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);

    pop();
    pop();
    pop();
    pop();

    for (int i = 0; i < Size - 1; i++)
    {
        cout << Stack[i] << " ";
    }
}