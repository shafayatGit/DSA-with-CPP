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
    cout << "input the size:";
    cin >> n;

    vector<int> daynamicV;        // dynamic array
    vector<int> fixedV(n);        // declaring size which is fixed array
    vector<int> v(n, 5);          // declaring size is n and every elems is 5
    vector<int> V = {1, 2, 3, 4}; // declaring like an array
    
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}