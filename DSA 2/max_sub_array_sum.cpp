#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxCrossingSum(const vector<int> &v, int l, int m, int r)
{
    int sum = 0, leftSum = INT_MIN;

    for (int i = m; i >= l; i--)
    {
        sum += v[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;

    for (int i = m + 1; i <= r; i++)
    {
        sum += v[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarray(const vector<int> &v, int l, int r)
{
    if (l == r)
        return v[l];

    int m = (l + r) / 2;

    return max({maxSubarray(v, l, m),
                maxSubarray(v, m + 1, r),
                maxCrossingSum(v, l, m, r)});
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cout << maxSubarray(v, 0, n - 1) << endl;
}