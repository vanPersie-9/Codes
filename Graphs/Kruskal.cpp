#include<bits/stdc++.h>
using namespace std;
int *p,*r;
int find(int x)
{
	while(x!=p[x])
        x=p[x];
	return x;
}
bool join(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b)
		return false;
	if(r[a]<r[b])
		p[a]=b;
	else if(r[b]<r[a])
		p[b]=a;
	else
	{
		p[a]=b;
		r[b]++;
	}
	return true;
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector< pair<int,pair<int,int> > > v;
	for(int i=0;i<m;i++)
	{
		int u,r,w;
		cin>>u>>r>>w;
		v.push_back(make_pair(w,make_pair(u,r)));
	}
	sort(v.begin(),v.end());
	p=new int[n+1];
	r=new int[n+1];
	for(int i=0;i<=n;i++)
	{
		r[i]=0;
		p[i]=i;
	}
	vector< pair<int,pair<int,int> > > ans;
	int cost=0;
	for(int i=0;i<m;i++)
	{
		pair<int,pair<int,int> > ed=v[i];
		if(join(ed.second.first,ed.second.second))
		{
			ans.push_back(ed);
			cost+=ed.first;
		}
	}
	if(ans.size()!=(n-1))
		cout<<"MST cannot be created"<<endl;
	else
	{
		cout<<"Cost of MST="<<cost<<endl;
		cout<<"Edges included in MST"<<endl;
		for(int i=0;i<n-1;i++)
			cout<<ans[i].second.first<<" "<<ans[i].second.second<<" "<<ans[i].first<<endl;
	}
}
/*
9 14
3 5 14
5 4 10
1 7 11
3 4 9
1 2 8
0 7 8
7 8 7
2 3 7
6 8 6
7 6 1
8 2 2
6 5 2
0 1 4
2 5 4
*/
