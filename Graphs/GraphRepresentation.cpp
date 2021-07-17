#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int q;
    cin >> q;
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        if(find(adj[a].begin(), adj[a].end(), b) == adj[a].end())
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
