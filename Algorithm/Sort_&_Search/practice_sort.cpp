#include <iostream>
using namespace std;

void Bubble_Ascending_Sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Bubble_Descending_Sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j + 1] > arr[j])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Selection_Ascending_Sort(int arr[], int size)
{
    int j, k;
    for (int i = 0; i < size; i++)
    {
        for (j = k = i; j < size; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }
}

void Selection_Descending_Sort(int arr[], int size)
{
    int j, k;
    for (int i = 0; i < size; i++)
    {
        for (j = k = i; j < size; j++)
        {
            if (arr[j] > arr[k])
            {
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }
}

void Insertion_Ascending_Sort(int arr[], int size)
{
    int j, key;
    for (int i = 1; i < size; i++)
    {
        j = i - 1;
        key = arr[i];
        while (j > -1 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void Insertion_Descending_Sort(int arr[], int size)
{
    int j, key;
    for (int i = 1; i < size; i++)
    {
        j = i - 1;
        key = arr[i];
        while (j > -1 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{ //[10,7]
    int arr[] = {10, 7, 3, 12, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Bubble_Ascending_Sort(arr, size);
    // Bubble_Descending_Sort(arr, size);

    // Selection_Ascending_Sort(arr, size);
    // Selection_Descending_Sort(arr, size);

    // Insertion_Ascending_Sort(arr, size);
    // Insertion_Descending_Sort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}