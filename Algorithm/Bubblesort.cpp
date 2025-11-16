#include <iostream>
using namespace std;

void BubbleSort()
{
    int arr[] = {8, 5, 7, 3, 2};
    for (int i = 0; i < 5 - 1; i++)
    {
        for (int j = 0; j < 5 - 1 - i; j++)
        {
            swap(arr[j], arr[j + 1]);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    BubbleSort();
}