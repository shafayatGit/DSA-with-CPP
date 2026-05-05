#include<iostream>
#include<vector>
using namespace std;
struct vial
{
    int potency;
    int toxicity;
    int quantity;
    
};

// global variable
int n, m; // no of coins
vector<vial>vials;
int imp_value=100000000; // impossible value for minimization problem

/// for memoization
int memo[1000][1000];

/// current item --> need to take decision on this.(should I take it or not)
/// rem_weight --> remaining weight to fill up.
/// returns the value gained
int solve(int current_vial,int rem_potency)
{
    ///base case
    if(current_vial==n && rem_potency>0) // no coin remaining, but change is not done
        return imp_value;
    if(rem_potency<0)
        return imp_value;
    if(rem_potency==0)
        return 0; // done giving the change


    /// memoization
    if(memo[current_vial][rem_potency]!=imp_value) /// it was solved before
        return memo[current_vial][rem_potency];


    /// decisions: should I take or not
    int ans=imp_value;
    for(int i=0;i<=vials[current_vial].quantity;i++)
    {
        /// how much I have given with current coin
        int given=i*vials[current_vial].potency;
        ans=min(ans,vials[current_vial].toxicity*i+solve(current_vial+1,rem_potency-given));
    }
    memo[current_vial][rem_potency]=ans;
    return ans;

}


int main()
{
    cin>>n >> m;
    for(int i=0; i<n; i++)
    {
        struct vial v;
        cin>> v.potency >> v.toxicity >> v.quantity;
        vials.push_back(v);

    }

    //change
    int rem_potency;
    rem_potency = m;

    ///memoization initialization
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=rem_potency;j++)
        {
            memo[i][j]=imp_value; /// that means the problem is yet to be solved
        }
    }

    //cout<<solve(0,rem_change)<<endl;

    int result = solve(0, rem_potency);

    if(result == imp_value)
        cout << -1 << endl;
    else
        cout << result << endl;

}