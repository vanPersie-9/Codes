#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl "\n"
#define mp make_pair
#define MOD 1000000007


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t,n,m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int a[n+1][m+1], dp[n+1][m+1];
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin >> a[i+1][j+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][j] = INT_MAX;
        if(a[n][m] < 0)
        {
            dp[n-1][m] = min(dp[n-1][m], 1+abs(a[n][m]));
            dp[n][m-1] = min(dp[n][m-1], 1+abs(a[n][m]));
        }
        else
        {
            dp[n][m-1]=1;
            dp[n-1][m]=1;
        }
        for(int i=n;i>=1;i--)
        {
            for(int j=m;j>=1;j--)
            {
                if(i==n && j==m)
                    continue;
                if(a[i][j]>0)
                {
                    dp[i-1][j] = min(dp[i-1][j], max(1,dp[i][j] - a[i][j]));
                    dp[i][j-1] = min(dp[i][j-1], max(1,dp[i][j] - a[i][j]));
                }
                else
                {
                    dp[i-1][j] = min(dp[i-1][j], dp[i][j]+abs(a[i][j]));
                    dp[i][j-1] = min(dp[i][j-1], dp[i][j]+abs(a[i][j]));
                }
            }
        }
        int ans;
        if(a[1][1]>0)
            ans = max(1, dp[1][1]-a[1][1]);
        else
            ans = dp[1][1]+abs(a[1][1]);
        cout << ans << endl;
    }
    
}