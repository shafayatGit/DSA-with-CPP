#include <iostream>
using namespace std;

int main()
{
    int arr[] = {6, 5, 12, 14, 18, 10};
    int j, x;
    for (int i = 1; i < 6; i++)
    {
        j = i - 1;
        x = arr[i];
        while (j > -1 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}