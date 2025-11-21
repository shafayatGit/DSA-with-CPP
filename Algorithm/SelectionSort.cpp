#include <iostream>
using namespace std;

int main()
{
    int arr[] = {4, 6, 2, 1, 5, 9};
    int j, k;
    for (int i = 0; i < 6 - 1; i++)
    {

        for (j = k = i; j < 6; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}
