#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int > > adj;
int parent[10000];
int ranks[10000];

int par(int x)
{
    while(x!=parent[x])
        x=parent[x];
    return x;
}
bool DSU(int a, int b)
{
    int x = par(a);
    int y = par(b);
    if(x!=y)
    {
        if(ranks[x]>ranks[y])
            parent[y]=x;
        else if(ranks[y]>ranks[x])
            parent[x]=y;
        else
        {
            parent[x]=y;
            ranks[y]++;
        }
    }
    else
        return false;
    return true;
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        adj.push_back(make_pair(x,y));
    }
    for(int i=1;i<=n;i++)
        parent[i]=i;
    for(int i=1;i<=n;i++)
        ranks[i]=0;
    for(int i=0;i<m;i++)
    {
        if(DSU(adj[i].first, adj[i].second)==false)
        {
            cout << "Cyclic";
            return 0;
        }
    }
    cout << "Non-Cyclic";
}
