#include <iostream>
using namespace std;

int add(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

void swapByValue(int a, int b) // using Pass By Value variable
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapByAddress(int *a, int *b) // using Pass By Address variable
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swapByReference(int &a, int &b) // using Pass By Reference variable
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int main()
{
    int x, y, z;

    x = 10;
    y = 20;

    z = add(x, y);
    cout << "Sum:" << z << endl;
    cout << "----Passing Params----"<< endl;

    swap(x, y); // using Pass By Value variable and that wont change the value of x and y
    cout <<"After Pass By Value:"<<"x:" << x << " y:" << y << endl;
    swapByAddress(&x, &y); // using Pass By Address variable and that will change the value of x and y
    cout <<"After Pass By Address:"<<"x:" << x << " y:" << y << endl;
    swapByReference(x, y); // using Pass By Reference variable and that will change the value of x and y
    cout <<"After Pass By Reference:"<<"x:" << x << " y:" << y << endl;

}