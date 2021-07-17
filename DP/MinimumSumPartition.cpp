#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        int s=0;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i], s+=a[i];
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
        int ans = INT_MAX;
        for(int i=0;i<=s/2;i++)
            if(dp[n][i])
                ans = min(ans, s-2*i);
        cout << ans << endl;
    }
}
