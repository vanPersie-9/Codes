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
const int MOD = 1e9+7;

const int N = 1e5+5;
int tree[4*N];
int a[N];

void build(int x, int st, int en)
{
    if(st==en)
    {
        tree[x] = a[st];
        return;
    }
    int mid = (st+en)/2;
    build(2*x+1,st,mid);
    build(2*x+2,mid+1,en);
    tree[x] = min(tree[2*x+1], tree[2*x+2]);
}

void update(int x, int st, int en, int ind, int val)
{
    if(st==en)
    {
        a[ind]=val;
        tree[x]=val;
        return;
    }
    int mid = (st+en)/2;
    if(st<=ind && ind<=mid)
        update(2*x+1,st,mid,ind,val);
    else
        update(2*x+2,mid+1,en,ind,val);
    tree[x] = min(tree[2*x+1],tree[2*x+2]);
}

int query(int x, int st, int en, int l, int r)
{
    if(l>en || r<st)
        return INT_MAX;
    if(st>=l && en<=r)
        return tree[x];
    int mid=(st+en)/2;
    int m1 = query(2*x+1,st,mid,l,r);
    int m2 = query(2*x+2,mid+1,en,l,r);
    return min(m1,m2);
}

int32_t main()
{
    TFiOS;

    int t,n;
    cin >> n >> t;
    for(int i=0;i<n;i++)
        cin >> a[i];
    build(0,0,n-1);
    while(t--)
    {
        char ch;
        cin >> ch;
        if(ch=='q')
        {
            int l,r;
            cin >> l >> r;
            l--;
            r--;
            cout << query(0,0,n-1,l,r) << endl;
        }
        else
        {
            int ind,val;
            cin >> ind >> val;
            ind--;
            update(0,0,n-1,ind,val);
        }
    } 
    return 0;
}