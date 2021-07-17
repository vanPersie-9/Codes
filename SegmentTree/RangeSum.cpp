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

void build(int x, int start, int end)
{
    if(start == end)
    {
        tree[x] = a[start];
        return;
    }
    int mid = (start+end)/2;
    build(2*x+1,start,mid);
    build(2*x+2,mid+1,end);
    tree[x] = tree[2*x+1]+tree[2*x+2];
}

void update(int x, int start, int end, int ind, int val)
{
    if(start==end)
    {
        a[ind]=val;
        tree[x]=val;
        return;
    }
    int mid = (start+end)/2;
    if(ind>=start && ind<=mid)
        update(2*x+1,start,mid,ind,val);
    else
        update(2*x+2,mid+1,end,ind,val);
    tree[x] = tree[2*x+1]+tree[2*x+2];
}

int query(int x, int start, int end, int l, int r)
{
    if(l>end || r<start)
        return 0;
    if(l<=start && r>=end)
        return tree[x];
    int mid = (start+end)/2;
    int s1 = query(2*x+1,start,mid,l,r);
    int s2 = query(2*x+2,mid+1,end,l,r);
    return s1+s2;
}

int32_t main()
{
    //TFiOS;

    int t,n;
    cin >> n >> t;
    for(int i=0;i<n;i++)
        cin >> a[i];
    build(0,0,n-1);
    /*for(int i=0;i<4*n;i++)
        cout << tree[i] << " ";
    cout << endl;*/
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