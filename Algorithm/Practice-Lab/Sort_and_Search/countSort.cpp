#include <iostream>
using namespace std;

void countSort(int arr[], int n)
{

    //?Step 1: Find max of the main array
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    //? Step 2: create Count array and initialized with 0
    int *count;
    count = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    //? Step 3: Main array er value Count array er index e boshaitesi and ++ kortesi
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    //? Step 4: Count array er upor loop chalabo max+1 porjonto and jodi count array er value 0 theke beshi hoy tahole main array er value te count array index boshabo(arr[i++]=j) and count array er value 1 komabo(count[j]--).. Or jodi 0 theke choto hoy amra shamne agabo (j++).

    int i = 0;
    int j = 0;
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

int main()
{
    int arr[] = {3, 1, 7, 19, 12, 24, 7, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}