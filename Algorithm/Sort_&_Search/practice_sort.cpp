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

void Count_Ascending_Sort(int arr[], int size)
{
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
        if (max > arr[i])
        {
            min = arr[i];
        }
    }

    int diff = max - min;

    int *count;
    count = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    int i, j = 0;
    while (j < max + 1)
    {
        if (count[j] > 0)
        {
            arr[i++] = j;
            count[j]--;
        }
        else
        {
            j++;
        }
    }
}

void Count_Descending_Sort(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    int *count;
    count = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    int i = 0, j = max;
    while (j >= 0)
    {
        if (count[j] > 0)
        {
            arr[i++] = j;
            count[j]--;
        }
        else
        {
            j--;
        }
    }
}
int main()
{ //[10,7]
    int arr[] = {-10, 7, -3, 12, -11};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Bubble_Ascending_Sort(arr, size);
    // Bubble_Descending_Sort(arr, size);

    // Selection_Ascending_Sort(arr, size);
    // Selection_Descending_Sort(arr, size);

    // Insertion_Ascending_Sort(arr, size);
    // Insertion_Descending_Sort(arr, size);

    Count_Ascending_Sort(arr, size);
    // Count_Descending_Sort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}