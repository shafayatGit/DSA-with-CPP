#include <iostream>
using namespace std;

void insertionSort(int arr[], int key, int size)
{
    int j;

    j = size - 1;
    while (j > -1 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

int main()
{
    int arr[] = {3, 8, 12, 20, 25};
    int key = 15;
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, key, size);

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}