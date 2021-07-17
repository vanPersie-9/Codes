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

    int t,n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        int dp[n][n];
        for(int i=0;i<n;i++)
            dp[i][i] = 0;
        for(int l=2;l<n;l++)
        {
            for(int i=1;i+l<=n;i++)
            {
                int j = i+l-1;
                dp[i][j] = INT_MAX;
                for(int k=i+1;k<=j;k++)
                    dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j] + a[i-1]*a[k-1]*a[j] );
            }
        }
        cout << dp[1][n-1] << endl;
    }
    
}