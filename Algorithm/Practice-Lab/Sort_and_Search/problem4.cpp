#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 7, 5, 3, 9, 1};
    for (int i = 1; i < 5; i=i+2)
    {
        for (int j =1; j < 6 - i - 1; j=j+2)
        {
            if (arr[j + 2] < arr[j])
            {
                swap(arr[j + 2], arr[j]);
            }
        }
    }

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}