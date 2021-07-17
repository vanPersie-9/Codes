#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10000];
int v[10000] = {0};
bool vis[10000];
int c=0;

void IsCyclicDFS(int u, int p)
{
    //cout << u << "->";
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++)
    {
        //cout << "**" << adj[u][i] <<"**\n";
        if(vis[adj[u][i]] == 0)
            IsCyclicDFS(adj[u][i], u);
        else if(v[adj[u][i]]!=p)
            c=1;
    }
    //v[u]=2;
}

int main()
{
    memset(v,0,sizeof(v));
    int n,m;      // nodes,edges
    cin >> n >> m;
    //vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //bool v[n+1]={0};
    int s;
    cin >> s;
    IsCyclicDFS(s, -1);
    if(c==1)
        cout << "Cyclic"<<endl;
    else
        cout << "Non-Cyclic" << endl;
    return 0;
}
