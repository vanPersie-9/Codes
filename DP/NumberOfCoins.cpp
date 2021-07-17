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
 //TFiOS;

    int t,n,m,v;
    cin >> t;
    while (t--)
    {
        cin >> v >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        int dp[v+1];
        dp[0] = 0;
        for(int i=1;i<=v;i++)   
            dp[i] = INT_MAX;
        for(int i=1;i<=v;i++)
            for(int j=0;j<n;j++)
                if(a[j]<=i)
                    dp[i] = min(dp[i], 1+dp[i-a[j]]);
        if(dp[v] == INT_MAX)
            cout << -1 << endl;
        else
            cout << dp[v] << endl;
    }
    
}