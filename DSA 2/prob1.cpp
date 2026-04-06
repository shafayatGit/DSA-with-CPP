// using vector, sort an array in descending order
#include <iostream>
#include <vector>
using namespace std;

/*
 +------------------+-----------------------+-------------------------+
 |     Feature      |      Static Array     |      Dynamic Vector     |
 +------------------+-----------------------+-------------------------+
 | Memory Location  | Stack (Fast)          | Heap (Slightly Slower)  |
 | Size Definition  | Fixed at Compile-time | Determined at Runtime   |
 | Resizing         | Impossible            | Automatic               |
 | Memory Overhead  | Zero                  | High (Pointers/Capacity)|
 | Performance      | Maximum               | High (Allocation cost)  |
 +------------------+-----------------------+-------------------------+
*/

int main()
{
    int n;
    cin >> n;

    vector<int> v;       // dynamic array
    vector<int> v(n);    // declaring size which is fixed array
    vector<int> v(n, 5); // declaring size is n and every elems is 5
}