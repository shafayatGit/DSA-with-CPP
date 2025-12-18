#include <iostream>
using namespace std;
struct Rectangle
{
    int length, breadth; // 4 bytes + 4 bytes = 8 Bytes
    //char x; character takes 1 byte but full stucture will take 4+4+4 = 12 bytes
};

int area(struct Rectangle r) // passing structure as a parameter and this is call by value
{   
    r.length = 20; // this will not change the original value of length. Only change when we use pointer means call by reference
    return r.length * r.breadth;
}

int areaUsingRef(struct Rectangle &r) // passing structure as a parameter and this is call by reference
{   
    r.length = 20; // this will change the original value of length bcz we used reference here.
    return r.length * r.breadth;
}

// Changing breadth using call by address
int changeBreadth(struct Rectangle *p)
{
    p->breadth = 500; // this will change the original value of breadth bcz we used pointer here.
    return p->breadth;
};

int main()
{
    //struct Rectangle r; //Only Declaration
    struct Rectangle r = {10,5};// ----->>> Declaration + Initialization
    r.length = 15; //can access using dot(.)
    r.breadth = 5; 
    cout<<"Area is:"<<r.length * r.breadth<<endl;
    cout<<sizeof(r.length)<<endl; //----> That will take 8 bytes bcz of the structure is 8 bytes
    cout<<sizeof(r.breadth)<<endl; //----> That will take 8 bytes bcz of the structure is 8 bytes
    //cout<<sizeof(r); //----> That will take 16 bytes bcz of the structure is 8+8 bytes

    cout<<"Area is:"<<areaUsingRef(r)<<endl; // passing structure as a parameter
    cout<<changeBreadth(&r)<<endl; // passing structure as a parameter using address.
}
