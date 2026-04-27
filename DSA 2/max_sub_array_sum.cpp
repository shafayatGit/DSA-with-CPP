#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cross_sum(int arr[], int si, int mid, int ei)
{

    int left_max_sum = INT_MIN;
    int right_max_sum = INT_MIN;

    int sum = 0;
    for (int i = mid; i >= si; i--)
    {
        sum += arr[i];

        if (left_max_sum < sum)
        {
            left_max_sum = sum;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= ei; i++)
    {
        sum += arr[i];

        if (right_max_sum < sum)
        {
            right_max_sum = sum;
        }
    }

    return left_max_sum + right_max_sum;
}

int maxSubArraySum(int arr[], int si, int ei)
{
    if (si == ei)
    {
        return arr[si];
    }

    int mid = (si + ei) / 2;
    int lss = maxSubArraySum(arr, si, mid);
    int rss = maxSubArraySum(arr, mid + 1, ei);
    int css = cross_sum(arr, si, mid, ei);

    return max(max(lss, rss), css);
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(int);
    cout << maxSubArraySum(arr, 0, n - 1) << endl; // 6
}