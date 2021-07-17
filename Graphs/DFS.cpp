#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10000];
bool v[10000];

void DFS(int u)
{
    cout << u << "->";
    v[u]=1;
    for(int i=0;i<adj[u].size();i++)
        if(!v[adj[u][i]])
            DFS(adj[u][i]);
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
    int c=0;
    for(int i=1;i<=n;i++)
        {
            if(!v[i])
                {
                    DFS(i);
                    c++;
                }
            else
                cout << endl;
        }
        cout << "\n"<<c << " components\n";
    return 0;
}
