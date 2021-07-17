/*
You are given a sequence A[1], A[2], ..., A[N] .
( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ).
A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries,
your program must output the results of these queries.
*/
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

const int N = 1e6+5;
struct Node
{
    int sum;
    int maxSum;
    int prefixSum;
    int suffixSum;
};
Node tree[4*N]={0};
int a[N];
int n,m;

void build(int x, int st, int en)
{
    if(st==en)
    {
        tree[x].sum = tree[x].maxSum = tree[x].prefixSum = tree[x].suffixSum = a[st];
        return;
    }
    int mid = (st+en)/2;
    build(2*x+1,st,mid);
    build(2*x+2,mid+1,en);
    tree[x].sum = tree[2*x+1].sum + tree[2*x+2].sum;
    tree[x].maxSum = max(max(tree[2*x+1].maxSum,tree[2*x+2].maxSum),tree[2*x+1].suffixSum+tree[2*x+2].prefixSum);
    tree[x].prefixSum = max(tree[2*x+1].prefixSum, tree[2*x+1].sum+tree[2*x+2].prefixSum);
    tree[x].suffixSum = max(tree[2*x+2].suffixSum,tree[2*x+2].sum+tree[2*x+1].suffixSum);
}

void update(int x, int st, int en, int ind, int val)
{
    if(st==en)
    {
        a[ind]=val;
        tree[x].sum = tree[x].maxSum = tree[x].prefixSum = tree[x].suffixSum = val;
        return;
    }
    int mid = (st+en)/2;
    if(ind<=mid)
        update(x,st,mid,ind,val);
    else
        update(x,mid+1,en,ind,val);

    tree[x].sum = tree[2*x+1].sum + tree[2*x+2].sum;
    tree[x].maxSum = max(max(tree[2*x+1].maxSum,tree[2*x+2].maxSum),tree[2*x+1].suffixSum+tree[2*x+2].prefixSum);
    tree[x].prefixSum = max(tree[2*x+1].prefixSum, tree[2*x+1].sum+tree[2*x+2].prefixSum);
    tree[x].suffixSum = max(tree[2*x+2].suffixSum,tree[2*x+2].sum+tree[2*x+1].suffixSum);

}

Node query(int x, int st, int en, int l, int r)
{
    if(l>en || r<st)
        return {0, INT_MIN, INT_MIN, INT_MIN};
    if(st>=l && en<=r)
        return tree[x];
    int mid=(st+en)/2;
    Node m1 = query(2*x+1,st,mid,l,r);
    Node m2 = query(2*x+2,mid+1,en,l,r);
    Node ans;

    ans.sum = m1.sum+m2.sum;
    ans.maxSum = max(max(m1.maxSum,m2.maxSum),m1.suffixSum+m2.prefixSum);
    ans.prefixSum = max(m1.prefixSum, m1.sum+m2.prefixSum);
    ans.suffixSum = max(m2.suffixSum,m2.sum+m1.suffixSum);
    return ans;
}

int32_t main()
{
    TFiOS

    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i];
    build(0,0,n-1);
    while(m--)
    {
        int x,y;
        cout << query(0,0,n-1,0,n-1).maxSum << endl;
        cin >> x >> y;
        update(0,0,n-1,x,y);
    }
    cout << query(0,0,n-1,0,n-1).maxSum << endl;
    return 0;
}

/*
4
1 2 3 4
4
1 1 3
0 3 -3
1 2 4
1 3 3
*/
