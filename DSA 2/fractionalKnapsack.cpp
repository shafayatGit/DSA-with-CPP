#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int>&a,pair<int,int>&b)
{
    if(1.0*a.first/a.second>1.0*b.first/b.second)
    {
        return true; /// do not want to swap
    }
    else
        return false; /// want to swap

}

int main()
{
    ///INPUT
    int n; // no of items
    cin>>n;
    vector<pair<int,int>>items;

    for(int i=0;i<n;i++)
    {
        int value, price;
        cin>>value>>price;
        items.push_back({value,price});

    }
    ///SORT
    sort(items.begin(),items.end(),compare);
    cout<<"after sorting-->"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<items[i].first<<" "<<items[i].second<<endl;
    }

    ///CHOOSE
    int limit,value_gained=0;
    cin>>limit;
    for(int i=0;i<n;i++)
    {
        if(limit==0) break;

        if(limit>=items[i].second) /// full item choose
        {
            limit-=items[i].second; /// deduct the price
            value_gained+=items[i].first; /// add the value
        }
        else if (limit<items[i].second) /// choose fraction of the item
        {

            float fraction=1.0*limit/items[i].second;
            value_gained+=1.0*fraction*items[i].first;
            limit=0;
        }
    }
    cout<<value_gained<<endl;


}

