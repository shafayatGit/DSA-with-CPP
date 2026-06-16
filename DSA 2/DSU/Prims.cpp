#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/// adj: an array of vector
/// adj[i]: there is a vector at adj[i], which stores the neighbors for node i
vector<pair<int,int>> adj[1000]; // for 1000 nodes
int n; // node count
bool locked[1000]; // to track the locked nodes, initially all false

int prims(int start)
{
    // pair because pair<key,label> for each node
    // to convert max heap to min heap heap, add: vector<type>, greater<type>
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
    // for start node, key is 0
    min_heap.push({0,start});
    int cost=0;
    while(!min_heap.empty())
    {
        pair<int,int> min_node=min_heap.top();
        /// pop
        min_heap.pop();
        int min_key=min_node.first;
        int min_label=min_node.second;
        /// lock
        if(locked[min_label]==true) // already locked, this node was processed prior
        {
            continue;
        }
        locked[min_label]=true; // first, lock it
        cost+=min_key; // add the cost

        // e represents all the <neighbor,weight> pairs for min label
        //push the neighbors inside heap
        for(auto e:adj[min_label])
        {
            int neighbor=e.first;
            int weight=e.second;
            if(locked[neighbor]==true) // neighbor locked, so don't change
                continue;
            min_heap.push({weight,neighbor}); ///update and push

        }


    }

    return cost;

}



int main()
{
    int m;
    cin>>n>>m; // n is node count, m is edge count

    for(int i=0;i<m;i++)
    {
        int u,v,weight; // u: start node, v:end node, weight: edge weight
        cin>>u>>v>>weight;
        //undirected graph
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }
    cout<<prims(1)<<endl;

}



