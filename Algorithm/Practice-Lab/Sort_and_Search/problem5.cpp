#include <iostream>
using namespace std;

int main()
{

    int arr[] = {8, 4, 6, 1, 3};
    int j, k;
    for (int i = 0; i < 4; i++)
    {
        for (j = k = i; j < 5; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        swap(arr[i], arr[k]);
        break;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}