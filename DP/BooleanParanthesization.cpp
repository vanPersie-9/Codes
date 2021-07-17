#include <bits/stdc++.h>
using namespace std;
#define TFiOS ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define int ll
#define pb push_back
#define endl "\n"
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

const int MOD =  1003;

int32_t main()
{
    TFiOS;

    int t,n;
    cin >> t;
    //t=1;
    while(t--)
    {
        cin >> n;
        string s,sym="",op="";
        cin >> s;
        for(int i=0;i<n;i++)
        {
            if(i&1)
                op.pb(s[i]);
            else
                sym.pb(s[i]);
        }
        n = (n+1)/2;
        int T[n][n], F[n][n];
        for(int i=0;i<n;i++)
        {
            F[i][i] = ((sym[i]=='F')?1:0);
            T[i][i] = ((sym[i]=='T')?1:0);
        }
        //cout << op << " " << n << " " << sym << endl;
        for(int L=1;L<n;L++)
        {
            for(int i=0;i+L<n;i++)
            {
                int j = i+L;
                T[i][j] = 0;
                F[i][j] = 0;
                for(int kk=0;kk<L;kk++)
                {
                    int k = i+kk;
                    int tik = T[i][k] + F[i][k];
                    int tkj = T[k+1][j] + F[k+1][j];

                    if(op[k] == '&')
                    {
                        T[i][j] = (T[i][j] + T[i][k]*T[k+1][j])%MOD;
                        F[i][j] = (F[i][j] + (tik*tkj - T[i][k]*T[k+1][j]))%MOD;
                    }
                    else if (op[k] == '|')
                    {
                        F[i][j] =  (F[i][j] + F[i][k]*F[k+1][j])%MOD;
                        T[i][j] =  (T[i][j] + (tik*tkj - F[i][k]*F[k+1][j]))%MOD;
                    }
                    else
                    {
                        T[i][j] =  (T[i][j] + F[i][k]*T[k+1][j] + T[i][k]*F[k+1][j])%MOD;
                        F[i][j] =  (F[i][j] + T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j])%MOD;
                    }
                }
            }
        }
        cout << T[0][n-1] << endl;
    }
    return 0;
}


