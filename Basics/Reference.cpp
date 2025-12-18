#include <iostream>
using namespace std;
int main(){
    int a = 10;
    int &r =a; // now what is a that is r.. for declaration must have to use "&" this.. it will take the same address and value also
    cout<<a<<endl;
    cout<<r<<endl;
    cout<<&a<<endl;
    cout<<&r<<endl;

    int b=20;
    r=b; //this is not declaration of reference bcz it will take only the value not the reference.
    

}