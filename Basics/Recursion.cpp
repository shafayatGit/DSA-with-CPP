#include <iostream>
using namespace std;

void print1toN ( int n ) {
if( n == 0) return ; // Base case
print1toN (n -1) ; // Recursive call.
cout << n << " ";
}

int main(){
    print1toN(10);
}