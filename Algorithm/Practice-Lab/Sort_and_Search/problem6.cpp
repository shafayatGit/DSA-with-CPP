#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int l = 0;
    int h = size - 1;
    int mid;
    for (int i = 0; i < size; i++)
    {
        mid = (l + h) / 2;
        if (key == arr[mid])
        {
            return mid;
        }
        else if (key < arr[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 5, 9, 12, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 12;
    int result = binarySearch(arr, size, key);
    cout << "Result: " << result;
}