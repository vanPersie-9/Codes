#include <bits/stdc++.h>
using namespace std;
#define TFiOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define int ll
#define pb push_back
#define endl "\n"
#define mp make_pair
#define ff first
#define ss second
const int MOD = 1e9+7;

int32_t main()
{
    TFiOS;

    int t,n,w;
    cin >> t;
    while(t--)
    {
        cin >> n >> w;
        int val[n], wt[n];
        for(int i=0;i<n;i++)    
            cin >> val[i];
        for(int i=0;i<n;i++)
            cin >> wt[i];
        int dp[n+1][w+1];
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        for(int i=0;i<=w;i++)
            dp[0][i] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(wt[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else 
                    dp[i][j] = max(dp[i-1][j], val[i-1]+ dp[i-1][j-wt[i-1]]);
            }
        }
        cout << dp[n][w] << endl;
    }
}