#include <iostream>
using namespace std;
class Rectangle // class is same as JAVA
{
private:
    int length, breadth;

public:
    Rectangle(int l, int b) // making constructor like JAVA
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    int getLength()
    { // getter
        return length;
    }
    void setLength(int l) //setter
    {
        length = l;
    }
    int getBreadth()
    { // getter
        return breadth;
    }
};

int main()
{
    Rectangle r(10, 5); // This is now an object like JAVA

    cout << "Initial Length:" << r.getLength() << " Initial Breadth:" << r.getBreadth() << endl;

    cout << "Area:" << r.area() << endl;

    r.setLength(20); // changing the length of the structure.
    cout << "Changed Length:" << r.getLength() << endl;
}
