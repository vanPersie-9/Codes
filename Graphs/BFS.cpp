#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10000];
bool v[10000];

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(!v[x])
        {
            cout << x << "->";
            v[x]=1;// x visited
            for(int j=0;j<adj[x].size();j++)
                if(!v[adj[x][j]]) // push all unvisited neighbouring nodes
                    q.push(adj[x][j]);
        }
    }
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
                    BFS(i);
                    c++;
                }
            else
                cout << endl;
        }
        cout << "\n"<<c << " components\n";
    return 0;
}
