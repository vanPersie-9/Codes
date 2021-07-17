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

    int t,n,k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int dp[n+1][k+1];
        for(int i=1;i<=n;i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for(int i=1;i<=k;i++)
            dp[1][i] = i;
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                dp[i][j] = INT_MAX; 
                for(int x=1;x<=j;x++)
                    dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][x-1], dp[i][j-x]));
            }
        }
        cout << dp[n][k] << endl;
    }
    return 0;
}