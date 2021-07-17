#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,n,t,m,p,r,a,s;
	cin>>t;
	while(t--)
    {
        cin >> n >> m;
        vector<pair<int,int> > v[n+1];
        vector<int> par(n+1,0);
        vector<int> dis(n+1,INT_MAX);
        par[1]=1;
        par[0]=0;
        for(i=0;i<m;i++)
        {
            cin >> a >> k >> p ;
            v[a].push_back(make_pair(k,p));
            if(a==1)
            {
                dis[k]=p;
                par[k]=1;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=2;j<=n;j++)
            {
                for(k=0;k<v[j].size();k++)
                {
                    int k2=v[j][k].first;
                    int k3=v[j][k].second;
                    if(dis[k2]>dis[j]+k3)
                    {
                        dis[k2]=dis[j]+k3;
                        par[k2]=j;
                    }
                }
            }
        }
        cout << "\nThe distance array is:\n";
        for(j=1;j<=n;j++)
            cout << dis[j] << "   ";
        cout << endl;
        cout << "Enter the nodes between which shortest path is to be found: ";
        cin >> k >> j;
        int pr1=j;
        while(pr1!=k)
        {
            cout << pr1 << " <- ";
            pr1=par[pr1];
        }
        cout << pr1 << endl;
    }
    return 0;
}
