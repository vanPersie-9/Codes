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

struct Box
{
    int l,w,h;
};

bool comp(Box a, Box b)
{
    int a1 = a.l*a.w;
    int a2 = b.l*b.w;
    return a1<a2;
}

int32_t main()
{
    TFiOS;

    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        Box a[n];
        for(int i=0;i<n;i++)
            cin >> a[i].h >> a[i].l >> a[i].w;
        Box newA[n*3];
        int ind=0;
        for(int i=0;i<n;i++)
        {
            newA[ind].h = a[i].h;
            newA[ind].l = max(a[i].w, a[i].l);
            newA[ind++].w = min(a[i].w, a[i].l);

            newA[ind].h = a[i].w;
            newA[ind].l = max(a[i].h, a[i].l);
            newA[ind++].w = min(a[i].l, a[i].h);

            newA[ind].h = a[i].l;
            newA[ind].l = max(a[i].w, a[i].h);
            newA[ind++].w = min(a[i].h, a[i].w);
        }
        n = 3*n;
        sort(newA,newA+n,comp);
        /*
            Sorting is done on area because smaller area box
            may be placed on larger area box but larger area
            box can never be placed on smaller area box.
        */
        int dp[n];
        for(int i=0;i<n;i++)
            dp[i] = newA[i].h;

        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                if(newA[j].l < newA[i].l && newA[j].w < newA[i].w)
                    dp[i] = max(dp[i], dp[j]+newA[i].h);

        int ans=-2;
        for(int i=0;i<n;i++)
            ans = max(ans, dp[i]);
        cout << ans << endl;
    }
    return 0;
}
