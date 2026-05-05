#include<iostream>
#include<vector>
using namespace std;
struct item
{
    int weight;
    int value;
};

// global variable
int n; // no of items
vector<item>items;
int imp_value=-100000000; // impossible value for maximization problem

/// for memoization
int memo[1000][1000];

/// current item --> need to take decision on this.(should I take it or not)
/// rem_weight --> remaining weight to fill up.
/// returns the value gained
int solve(int current_item,int rem_weight)
{
    ///base case
    if(current_item==n) // no items remaining
        return 0;
    if(rem_weight<items[current_item].weight)
        return solve(current_item+1,rem_weight) ; /// skip that item

    /// memoization
    if(memo[current_item][rem_weight]!=imp_value) /// it was solved before
        return memo[current_item][rem_weight];


    /// decisions: should I take or not
    int taken= items[current_item].value +
               solve(current_item+1, rem_weight-items[current_item].weight);
    int not_taken= solve(current_item+1,rem_weight);
    int ans=max(taken,not_taken);
    // save the answer
    memo[current_item][rem_weight]=ans;
    return ans;

}


int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        struct item it;
        cin>>it.weight>>it.value;
        items.push_back(it);

    }

    //knapsack weight
    int rem_weight;
    cin>>rem_weight;

    ///memoization initialization
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=rem_weight;j++)
        {
            memo[i][j]=imp_value; /// that means the problem is yet to be solved
        }
    }

    cout<<solve(0,rem_weight)<<endl;


}