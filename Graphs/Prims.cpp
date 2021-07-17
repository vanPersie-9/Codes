#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll prim(vector<pair<ll,ll> > adj[],ll s,ll n)
{
	vector<bool> vis(n+1,false);
	vector<ll> key(n+1, INT_MAX);
	vector<ll> parent(n+1,-1);
    ll i,j,k,t,c=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
	pq.push(make_pair(0,s));
	key[s]=0;
	while(!pq.empty())
	{
		ll u =pq.top().second;
		pq.pop();
		if(!vis[u])
		{
		    vis[u]=1;
            c+=key[u];
		}
		for(j=0;j<adj[u].size();j++)
		{
			ll  v=adj[u][j].first;
			ll  wt=adj[u][j].second;
			if(!vis[v] && key[v]>wt)
            {
                //c+=wt;
                key[v]=wt;
                pq.push(make_pair(key[v],v));
                parent[v]=u;
            }
		}
	}
    for(int i=1;i<=n ;i++)
    {
        if(i==s)
            continue;
        cout << parent[i] << "-" << i << endl;
        //c+=adj[parent[i]][i].second;
    }
    cout << c << endl;
}
int main()
{
	ll  i,j,k,n,t,m,p,r,a,s;
    cin>>n>>m;
    vector<pair<ll,ll> > adj[n+1];
    for(j=0;j<m;j++)
    {
        cin>>k>>p>>a;
        adj[k].push_back(make_pair(p,a));
        adj[p].push_back(make_pair(k,a));
    }
    prim(adj,1,n);
	//cout<<mini<<endl;
	return 0;
}
