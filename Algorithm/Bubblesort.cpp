#include <iostream>
using namespace std;

void BubbleSort()
{
    int arr[] = {8, 5, 7, 3, 2, 9};
    for (int i = 0; i < 6 - 1; i++)
    {
        for (int j = 0; j < 6 - 1 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(arr[j], arr[j + 1]); //bubble sort e amra ekta ekta kore dekhei swap kore dei
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    BubbleSort();
}