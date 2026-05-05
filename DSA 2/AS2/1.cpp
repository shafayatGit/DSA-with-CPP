#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int  trans_cost;

bool compare(pair<int,int>&a,pair<int,int>&b)
{
    if(((1.0*a.first/a.second)-trans_cost)>((1.0*b.first/b.second) - trans_cost))
    {
        return true; /// do not want to swap
    }
    else
        return false; /// want to swap

}

int main()
{
    ///INPUT
    int n, limit; // no of items
    cin>>n >> limit >> trans_cost;
    vector<pair<int,int>>items;

    for(int i=0;i<n;i++)
    {
        int value, price;
        cin>>value>>price;
        items.push_back({value,price});

    }
    ///SORT
    sort(items.begin(),items.end(),compare);
    // cout<<"after sorting-->"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<items[i].first<<" "<<items[i].second<<endl;
    // }

    ///CHOOSE
    float value_gained=0;
    
    for(int i=0;i<n;i++)
    {
        if(limit==0) break;

        else if(limit>=items[i].second) /// full item choose
        {

            int value_to_add = (items[i].first - items[i].second * trans_cost);
            if(value_to_add >= 0)
            {
                value_gained+= value_to_add;
                limit-=items[i].second;
            }
             /// add the value
        }
        else if (limit<items[i].second) /// choose fraction of the item
        {

            float fraction=1.0*items[i].first/items[i].second;
            float value_to_add = (1.0*fraction*limit - limit*trans_cost);
            if (value_to_add >= 0)
            {
                value_gained+=(1.0*fraction*limit - limit*trans_cost);
                limit=0;
            }
            
        }
    }
    cout<<value_gained<<endl;


}

