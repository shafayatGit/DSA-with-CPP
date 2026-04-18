#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Merge Sort

void merge(vector<int> &v, int start, int mid, int end)
{
    // left array: start -> mid
    // right array: mid+1 ->end
    int i = start;
    int j = mid + 1;
    vector<int> sorted;
    while (i <= start && j <= mid + 1)
    {
        if (v[i] < v[j])
        {
            sorted.push_back(v[i]);
            i++;
        }
        else
        {
            sorted.push_back(v[j]);
            j++;
        }
    }
    if(i>mid){
        while(j<mid){
            sorted.push_back(v[j]);
        }
    }
}

void mergeSort(vector<int> &v, int start, int end)
{
    // base case
    if (end - start == 1)
    {
        if (v[start > v[end]])
        {
            swap(v[start], v[end]);
            return;
        }
    }
    if (start == end)
    {
        return;
    }
    // devide
    int mid = (start + end) / 2;
    mergeSort(v, start, end);
    mergeSort(v, mid + 1, end);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
}