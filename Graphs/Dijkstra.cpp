#include<bits/stdc++.h>
using namespace std;

inline void dijkstra(vector<pair<int,int> > adj[], int s, int n,vector<int> &dist)
{
	vector<bool> vis(n+1, false);
	int i,j,k,p,t;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	for(j=0;j<=n;j++)
        dist[j]=INT_MAX;
	dist[s]=0;
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{
		int k1=pq.top().second;
		pq.pop();
		if(vis[k1])
            continue;
		vis[k1]=true;
		for(j=0;j<adj[k1].size();j++)
		{
			int k2=adj[k1][j].first;
			int k3=adj[k1][j].second;
			if(dist[k2]>dist[k1]+k3)
                dist[k2]=dist[k1]+k3;
            if(!vis[k2])
                pq.push(make_pair(dist[k2],k2));
		}
	}
}
int main()
{
	int i,j,k,n,t,m,p,r,a,s;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>m;
		vector<pair<int,int> > adj[n+1];
		for(j=0;j<m;j++)
		{
			cin>>k>>p>>a;
			adj[k].push_back(make_pair(p,a));
			//adj[p].push_back(make_pair(k,a));
		}
		cin>>s;
		vector<int> dist(n+1,0);
		dijkstra(adj,s,n,dist);
		for(j=1;j<=n;j++)
        {
            if(j!=s)
            {
                if(dist[j]!=INT_MAX)
                    cout<<dist[j]<<" ";
                else
                    cout<<"-1 ";
            }
        }
        cout<<endl;
	}
	return 0;
}
/*
1
9 14
1 2 4
1 8 8
2 8 11
2 3 8
3 9 2
9 7 6
9 8 7
7 8 1
6 5 2
3 6 4
3 4 7
4 5 9
6 5 10
4 6 14
1
*/
