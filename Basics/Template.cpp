#include <iostream>
using namespace std;

template <class T>
class Arithmetic
{
private:
    T a, b; // T means it can take any data type and thats called generic datatype
public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b) // Must use Template<class T> before defining the function outside the class and use Arithmetic<T> instead of Arithmetic
{
    this->a = a; // this is used to differentiate the local and global variable
    this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
    T c;
    c = a + b;
    return c;
}

template <class T>
T Arithmetic<T>::sub()
{
    return a - b;
}

int main()
{
    Arithmetic<int> ar(10, 5); // Here we are creating object of type int from the main function.
    cout << "Add: " << ar.add() << " Sub: " << ar.sub() << endl;
    Arithmetic<float> arf(5.5, 2.5); // Here we are creating object of type float from the main function.
    cout << "Add: " << arf.add() << " Sub: " << arf.sub() << endl;
}
