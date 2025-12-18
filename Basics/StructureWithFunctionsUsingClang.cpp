#include <iostream>
using namespace std;
struct Rectangle
{
    int length, breadth;
};

void initialize(struct Rectangle *r, int l, int b) // using pointer to initialize the structure and taking the value
{
    r->length = l;  // using arrow(->) to access the members of the structure using pointer
    r->breadth = b; // using arrow(->) to access the members of the structure using pointer
}

void changeLength(struct Rectangle *r, int l) // using pointer to change the length of the structure and taking the value
{
    r->length = l; // using arrow(->) to access the members of the structure using pointer
}

int area(struct Rectangle R)
{
    return R.length * R.breadth;
}

int main()
{
    struct Rectangle R;
    initialize(&R, 10, 5); // passing the address of the structure
    cout << "Initial Length:" << R.length << " Initial Breadth:" << R.breadth << endl;

    cout << "Area:" << area(R) << endl;
    
    changeLength(&R, 20); // changing the length of the structure.
    cout << "Changed Length:" << R.length << endl;
}