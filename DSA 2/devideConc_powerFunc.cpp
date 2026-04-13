#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// calculate x^n;

int power_x(int x, int n)
{

    // base case
    if (n == 1)
        return x;

    // devide
    int smaller = power_x(x, n / 2);

    // conquer
    if (n % 2 == 1)
    {
        return smaller * smaller * x;
    }
    else
    {
        return smaller * smaller;
    }
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << power_x(x, n) << endl;
}