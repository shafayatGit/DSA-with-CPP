#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the vector:";
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int target;
    cin >> target;

    bool exists = binary_search(v.begin(), v.end(), target);

    auto lb = lower_bound(v.begin(), v.end(), target); // using auto cause we dont want harcoded type
    auto up = upper_bound(v.begin(), v.end(), target);
    int count = up - lb;
    cout << *up << endl;

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
}
