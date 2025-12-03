#include <iostream>
using namespace std;

void selectionSort(int arr[], int mid)
{
    int j, k;
    for (int i = 0; i < mid - 1; i++)
    {
        for (j = k = i; j < mid; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }
}

int main()
{
    int arr[] = {9, 4, 1, 6, 8, 2, 7, 5};
    int l, h;
    l = 0;
    h = sizeof(arr) / sizeof(arr[0]);
    int mid = (h + l) / 2;
    selectionSort(arr, mid);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
}
