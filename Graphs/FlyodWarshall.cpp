#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll i,j,k,n,t;
    cin >> n;
    vector<ll> dp1(n+1,INT_MAX);
    vector< vector<ll> > dp(n+1,dp1);
    vector<ll> adj[n+1];
    cin >> t;
    for(i=1;i<=n;i++)
        dp[i][i]=0;
    for(i=0;i<t;i++)
    {
        ll p;
        cin >> j >> k >> p;
        adj[j].push_back(k);
        dp[j][k]=p;
    }
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                dp[i][j]=min(dp[i][j],dp[i][k] + dp[k][j]);
    cout << endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(dp[i][j]!=INT_MAX)
                cout << dp[i][j] << "\t";
            else
                cout << -1 << "\t";
        }
        cout << endl;
    }
    cout << "Enter the nodes between which shortest path is to be found: ";
    cin >> j >> k;
    ll val=dp[j][k];
    ll last=j;
    vector<ll> path;
    cout << "val=" << val << endl;
    path.push_back(last);
    ll c=0;
    while(last!=k)
    {
        for(t=0;t<adj[last].size();t++)
        {
            ll k1=adj[last][t];
            if(dp[last][k1]+dp[k1][k]==val)
            {
                path.push_back(k1);
                val-=dp[last][k1];
                last=k1;
                break;
            }
        }
        c++;
        if(c==n-1)
            break;
    }
    for(j=0;j<path.size();j++)
        cout << path[j] << " ";
    cout << endl;
}
