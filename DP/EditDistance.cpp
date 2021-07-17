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
    
    int t,m,n;
    string s1,s2;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> s1 >> s2;
        int dp[n+1][m+1];
        int ans = 0;
        for(int i=0;i<=n;i++)
            dp[i][0] = i;
        for(int i=0;i<=m;i++)
            dp[0][i] = i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
        cout << dp[n][m] << endl;
    }
}