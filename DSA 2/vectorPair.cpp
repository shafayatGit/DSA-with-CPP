// sort pairs based on the second element (custom elements)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compareFunc(pair<int, int> &a, pair<int, int> &b) // using this for time complexity so that we are taking address
{
    // a comes before b
    // if we dont want to swap, return true
    // else return false
    if (a.second > b.second)
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
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "Enter the " << i << " th pair:" && cin >> a >> b;
        v.push_back({a, b});
    }

    // sort(v.begin(), v.end());              // always sort according to first one
    sort(v.begin(), v.end(), compareFunc); // sorting using own function

    cout << "After sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
}