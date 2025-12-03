#include <iostream>
using namespace std;

int main()
{
    int arr[] = {4, 9, 2, 7, 1, 5};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6 - i - 1; j++)
        {
            if (arr[j + 1] > arr[j])
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}