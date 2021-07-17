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
    while(t--)
    {
        cin >> n;
        int a[n], s=0;
        for(int i=0;i<n;i++)
            cin >> a[i], s+=a[i];
        if(s&1)
        {
            cout << "NO\n";
            continue;
        }
        s = s/2;
        bool dp[n+1][s+1];
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=s;i++)
            dp[0][i] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=s;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=a[i-1])
                    dp[i][j] |= dp[i-1][j-a[i-1]];
            }
        }
        if(dp[n][s])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}