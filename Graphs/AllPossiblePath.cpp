#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
bool vis[100001];
int path=0;

void DFS_NoOfPaths(int u, int v)
{
    vis[u]=1;
    if(u==v)
        path++;
    else
    {
            for(int i=0;i<adj[u].size();i++)
            {
                if(!vis[adj[u][i]])
                    DFS_NoOfPaths(adj[u][i],v);
            }
    }
    vis[u]=0;
}

int main()
{
    memset(vis,0,sizeof(vis));
    int n,m,u,v;      // nodes,edges
    cin >> n >> m;
    //vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >>u >> v;
    DFS_NoOfPaths(u,v);
    cout << path;
}
