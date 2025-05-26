#include<iostream>
using namespace std;
#include<vector>

//DFS + asking the question to the neighbour can you come on me or the node that comes before me 

void criticalconnections(int node,int parent,vector<int>adj[],vector<int>&disc,vector<int>&low,vector<int>&visited,int count,vector<vector<int>>&bridges)
{

    disc[node]=low[node]=count;
    
    visited[node]=1;

    for(int i=0;i<adj[node].size();i++)
    {
        int neigh = adj[node][i];

        if(neigh==parent)
        continue;

        else if(visited[neigh])
        {
            low[node] = min(low[node],low[neigh]);
        }

        else
        {
            count++;
            criticalconnections(neigh,node,adj,disc,low,visited,count,bridges);

            if(disc[node]<low[neigh])
            {
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(neigh);
                bridges.push_back(ans);
            }

            low[node] = min(low[node],low[neigh]);
        }
    }
}

int main()
{
    cout<<"Enter the no. of vertices and Edges:-";
    int vertex,edges;
    cin>>vertex;
    cin>>edges;

    vector<int>adj[vertex];

    for(int i=0;i<edges;i++)
    {
        cout<<"Enter u:";
        int u;
        cin>>u;
        cout<<"Enter v:";
        int v;
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int>disc(vertex,0);
    vector<int>low(vertex,0);
    vector<int>visited(vertex,0);
    vector<vector<int>>bridges;

    int count=0;

    criticalconnections(0, -1, adj, disc, low, visited, count, bridges);

    for(int k=0;k<bridges.size();k++)
    {
            cout<<bridges[k][0]<<" "<<bridges[k][1];
            cout<<endl;
    }

}













