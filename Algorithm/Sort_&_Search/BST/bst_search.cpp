#include <iostream>
using namespace std;
struct Node
{
    struct Node *lChild;
    int data;
    struct Node *rChild;
} *root = NULL;

// ->Normal Insertion
void Insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;

    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lChild = p->rChild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lChild;
        }
        else if (key > t->data)
        {
            t = t->rChild;
        }
        else
        {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lChild = p->rChild = NULL;

    if (key < r->data)
    {
        r->lChild = p;
    }
    else
    {
        r->rChild = p;
    }
}

// -> Recursive Insertion
struct Node *RInsert(Node *p, int data)
{

    struct Node *t = NULL;
    if (p == NULL)
    {
        t = new Node;
        t->data = data;
        t->lChild = t->rChild = NULL;
        return t;
    }

    if (data < p->data)
    {
        p->lChild = RInsert(p->lChild, data);
    }
    else if (data > p->data)
    {
        p->rChild = RInsert(p->rChild, data);
    }
    return p;
}
// -> InOrder
void InOrder(struct Node *p)
{
    if (p)
    {
        InOrder(p->lChild);
        cout << p->data << " ";
        InOrder(p->rChild);
    }
}

// -> PreOrder
void PreOrder(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        PreOrder(p->lChild);
        PreOrder(p->rChild);
    }
}

// ->PostOrder
void PostOrder(struct Node *p)
{
    if (p)
    {
        PostOrder(p->lChild);
        PostOrder(p->rChild);
        cout << p->data << " ";
    }
}
//-> Recursive Search
struct Node *RSearch(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    else if (key < p->data)
        return RSearch(p->lChild, key);
    else
    {
        return RSearch(p->rChild, key);
    }
}

/* =========================
   MINIMUM
   ========================= */
Node *Tree_Minimum(Node *x)
{
    while (x->lChild != NULL)
        x = x->lChild;
    return x;
}

/* =========================
   MAXIMUM
   ========================= */
Node *Tree_Maximum(Node *x)
{
    while (x->rChild != NULL)
        x = x->rChild;
    return x;
}

/* =========================
   SUCCESSOR
   ========================= */
Node *Tree_Successor(Node *p)
{
    while (p && p->lChild != NULL)
    {
        p = p->lChild;
    }
    return p;
}

/* =========================
   PREDECESSOR
   ========================= */
Node *Tree_Predecessor(Node *p)
{
    while (p && p->rChild != NULL)
    {
        p = p->rChild;
    }
    return p;
}

int Height(Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = Height(p->lChild);
    y = Height(p->rChild);
    return x > y ? x + 1 : y + 1;
}

struct Node *Delete(Node *p, int key)
{
    struct Node *q;
    if (p == NULL)
        return NULL;
    if (p->lChild == NULL && p->rChild == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    if (key < p->data)
        p->lChild = Delete(p->lChild, key);
    else if (key > p->data)
        p->rChild = Delete(p->rChild, key);
    else
    {
        if (Height(p->lChild) > Height(p->rChild))
        {
            q = Tree_Predecessor(p->lChild);
            p->data = q->data;
            p->lChild = Delete(p->lChild, q->data);
        }
        else
        {
            q = Tree_Successor(p->lChild);
            p->data = q->data;
            p->rChild = Delete(p->rChild, q->data);
        }
    }
    return p;
}
int main()
{
    struct Node *temp;
    struct Node *pre;

    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 20);
    RInsert(root, 8);
    RInsert(root, 30);

    Delete(root, 10);

    InOrder(root);
    cout << endl;
    PreOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    pre = Tree_Predecessor(root);
    cout << "Predecessor:" << pre->data;

    temp = RSearch(root, 5);
    if (temp)
    {
        cout << "Data found" << temp->data;
    }
    else
    {
        cout << "Not found";
    }
}