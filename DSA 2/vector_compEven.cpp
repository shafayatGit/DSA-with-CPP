#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// pairs, whose summation is an even number should come first
bool compareFunc(pair<int, int> a, pair<int, int> b)
{
    if ((a.first + a.second) % 2 == 1 && (b.first + b.second) % 2 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "Enter the " << i << " th pair:" && cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cout << "(" << v[i].first << "," << v[i].second << ")" << endl;
    }
}