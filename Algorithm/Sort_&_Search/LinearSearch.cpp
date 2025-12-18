#include <iostream>
using namespace std;

int linearSearch(int arr[], int key, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (key == arr[i])
            return i;
    }
    return -1;
}

int main()
{
    int arr[] = {8, 9, 4, 7, 6, 3, 10, 5, 14, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 19;
    int result = linearSearch(arr, key, size);
    cout<<"Result: "<<result;
}