#include <iostream>
using namespace std;

struct Rectangle
{
    int length, breadth;
};

int main()
{
    int a = 10; // general declaration without pointer
    int *b;     // declaration of pointer.. star(*) is used only in declaration.
    b = &a;
    cout << "Bytes taking by a pointer: " << sizeof(b) << endl;
    cout << "This is the address of a: " << &a << endl;
    cout << "This is the value of a: " << *b << endl;               // *b mane value ashbe direct
    cout << "This is the address of a from pointer: " << b << endl; // shudhu b mane a er address ashbe.

    int *p;
    p = new int[5]; // initializing and accessing from Heap memory in C++ and then we have to delete also the memory from the heap
    int A[4] = {0, 1, 2, 3};
    p = A; // Cant use *p=A and also p=&A in the pointer array
    for (int i = 0; i < 4; i++)
    {
        cout << p[i] << endl; // if we dont use star(*) then it will print values and if we use star then it will print addresses
    }
    // delete[] p; // deleting from the heap memory that is using in C++

    cout << "------------Checking Sizes-------------" << endl;
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;
    cout << sizeof(p5) << endl;

    cout << "-------------------------" << endl;
    Rectangle r2 = {20, 30}; // we can use just Name in c++ compiler but we need to write struct in c compiler
    Rectangle *p6 = &r2;     // initializing with declaration
    p6->length = 40;         // if we want to assign value using pointer we have to use arrow
    // OR-----
    (*p6).breadth = 60; // Or we can use like this
    cout << r2.length << " " << r2.breadth << endl;

    // *********For Taking the memory in HEAP**********
    Rectangle *pointer;
    pointer = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    pointer->breadth = 2;
    pointer->length = 1;

    cout << "------From the Heap------" << endl
         << pointer->breadth << " " << pointer->length << endl;
}