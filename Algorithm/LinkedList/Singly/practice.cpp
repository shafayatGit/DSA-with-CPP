#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int id;

    Student(string n, int id)
    {
        name = name;
        id = id;
    }
};

struct Node
{
    string name;
    int id;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{

    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node)); // Or first = new Node;-> creating a new node.
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
void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->name << "," << " ID: " << p->id << endl;
        p = p->next;
    }
    cout << endl;
}

// Insert
void Insert(struct Node *p, int index, string name, int id)
{
    struct Node *t = new Node;
    t->name = name;
    t->id = id;
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
        // x = q->data;
        delete q;
        // return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        // x = p->data;
        delete p;
        // return x;
    }
}

// Count
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

int main()
{
    // in the insertion i have to maintain the index serialization or it will be exceed the index
    // Insert(first, 0, 'A');
    // Insert(first, 1, 'C');
    // Insert(first, 2, 'D');
    // Insert(first, 3, 'D');
    // Insert(first, 0, 'Z');
    // Insert(first, Count(first), 'L');
    // Delete(first, 1);
    // Student arr[2] = {{"Shafayat",101},{"Hossain",102}};

    // for(int i = 0; i < 2; i++)
    //     cout << arr[i].name << "," << arr[i].id << endl;

    // Insert(first, 0, "Shafayat", 101);
    // Insert(first, 1, "Hossain", 102);
    // Display(first);
}
