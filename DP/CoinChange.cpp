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

    int t,n,m;
    cin >> t;
    while (t--)
    {
        cin >> n ;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        cin >> m;
        int dp[n+1][m+1];
        for(int i=0;i<=m;i++)   
            dp[0][i] = 0;
        for(int i=1;i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j-a[i-1]>=0)
                    dp[i][j] += dp[i][j-a[i-1]];
            }
        }
        cout << dp[n][m] << endl;
    }
    
}

/*

https://imgur.com/a/QASHBAD

*/