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
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        int dp[n];
        for(int i=0;i<n;i++)    
            dp[i] = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[j] < a[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        int ans = 1;
        for(int i=0;i<n;i++)
            ans = max(ans,dp[i]);
        cout << ans << endl;
    }
}