#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int l, h, mid;

    l = 0;
    h = size - 1;
    while (l <= h)
    {
        mid = (h + l) / 2;
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
    int arr[] = {4, 8, 10, 15, 18, 21, 25, 27, 28, 30, 31, 32, 35,38};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 32;

    int result = binarySearch(arr, size, key);
    cout << "Result: " << result;
}