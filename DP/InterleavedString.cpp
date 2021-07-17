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
    
    int t,m,n,l;
    string A,B,C;
    cin >> t;
    while(t--)
    {
        cin >> A >> B >> C;
        l = A.length();
        m = B.length();
        n = C.length();
        if(n!=l+m)
        {
            cout << 0 << endl;
            continue;
        }
        bool dp[l+1][m+1];
        memset(dp, false, sizeof(dp));
        for(int i=0;i<=l;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = 1;
                else if(i==0)
                {
                    if(B[j-1]==C[i+j-1])
                        dp[i][j] = dp[i][j-1];
                }
                else if(j==0)
                {
                    if(A[i-1]==C[i+j-1])
                        dp[i][j] = dp[i-1][j];
                }
                else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1])
                    dp[i][j] = dp[i-1][j];
                else if(A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1])
                    dp[i][j] = dp[i][j-1];
                else if(A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1])
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            }
        }
        cout << dp[l][m] << endl;
    }
}