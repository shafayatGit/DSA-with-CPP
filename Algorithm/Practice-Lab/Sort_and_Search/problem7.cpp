#include <iostream>
using namespace std;

int lowerBound(int arr[], int key, int size)
{
    int l = 0;
    int h = size - 1;
    int mid;
    for (int i = 0; i < 6; i++)
    {
        mid = (l + h) / 2;
        if (key > arr[mid])
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    return l;
}

int main()
{
    int arr[] = {2, 4, 4, 4, 7, 9, 11};
    int key = 4;
    int size = sizeof(arr) / sizeof(arr[0]);
    int res = lowerBound(arr, key, size);

    cout << res;
}