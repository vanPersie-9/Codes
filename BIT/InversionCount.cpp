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

int getSum(int BIT[], int x)
{
    int s=0;
    while(x>0)
    {
        s+=BIT[x];
        x -= (x&-x);
    }
    return s;
}

void update(int BIT[], int n, int x, int val)
{
    while(x<=n)
    {
        BIT[x]+=val;
        x += (x&-x);
    }
}

void convert(int a[], int n)
{
    int tmp[n];
    for(int i=0;i<n;i++)
        tmp[i] = a[i];
    sort(tmp,tmp+n);
    for(int i=0;i<n;i++)
        a[i] = lower_bound(tmp,tmp+n,a[i])-tmp+1;
}

int countInversion(int a[], int n)
{
    convert(a, n);

    int BIT[n+1] = {0};
    int invCnt = 0;
    for(int i=n-1;i>=0;i--)
    {
        invCnt += getSum(BIT, a[i]-1);
        update(BIT, n, a[i], 1);
    }
    return invCnt;
}

int32_t main()
{
    TFiOS;

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)    
            cin >> a[i];
        cout << countInversion(a,n) << endl;
    }
}