#include <iostream>
using namespace std;

struct Rectangle{
    int length,breadth;
};
int area(Rectangle *r)
{
    return r->length*r->breadth;
}
int peri(Rectangle *r)
{
    return 2 * (r->length + r->breadth);
}

int main()
{
    Rectangle r;
    cout << "Enter Length:" && cin >> r.length; // we can take input and output in same line using &&

    cout << "Enter Breadth:" && cin >> r.breadth;
    
}