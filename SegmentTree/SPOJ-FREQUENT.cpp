/*
You are given a sequence of n integers a1 , a2 , ... , an 
in non-decreasing order. In addition to that, you are given
several queries consisting of indices i and j (1 ≤ i ≤ j ≤ n). 
For each query, determine the most frequent value 
among the integers ai , ... , aj.
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
    int maxFreq;
    int leftFreq;
    int rightFreq;
};
Node tree[4*N]={0};
int a[N];
int n,q,t;

void build(int x, int st, int en)
{
    if(st==en)
    {
        tree[x].maxFreq = tree[x].leftFreq = tree[x].rightFreq = 1;
        return;
    }
    int mid = (st+en)/2;
    build(2*x+1,st,mid);
    build(2*x+2,mid+1,en);
    tree[x].maxFreq = max(tree[2*x+1].maxFreq, tree[2*x+2].maxFreq);
    tree[x].leftFreq = tree[2*x+1].leftFreq;
    tree[x].rightFreq = tree[2*x+2].rightFreq;

    if(a[mid]==a[mid+1])
    {
        tree[x].maxFreq = max(tree[x].maxFreq, tree[2*x+1].rightFreq+tree[2*x+2].leftFreq);
        if(a[mid+1]==a[en])
            tree[x].rightFreq+=tree[2*x+1].rightFreq;
        if(a[st]==a[mid])
            tree[x].leftFreq+=tree[2*x+2].leftFreq;
    }
}

Node query(int x, int st, int en, int l, int r)
{
    if(l>en || r<st)
        return {INT_MIN, 0, 0};
    if(st>=l && en<=r)
        return tree[x];
    int mid=(st+en)/2;
    Node m1 = query(2*x+1,st,mid,l,r);
    Node m2 = query(2*x+2,mid+1,en,l,r);
    Node ans;

    ans.maxFreq = max(m1.maxFreq, m2.maxFreq);
    ans.leftFreq = m1.leftFreq;
    ans.rightFreq = m2.rightFreq;

    if(a[mid]==a[mid+1])
    {
        ans.maxFreq = max(ans.maxFreq, m1.rightFreq+m2.leftFreq);
        if(a[mid+1]==a[en])
            ans.rightFreq+=m1.rightFreq;
        if(a[st]==a[mid])
            ans.leftFreq+=m2.leftFreq;
    }
    return ans;
}

int32_t main()
{
    TFiOS
    
    //cin >> t;
    while (1)
    {
        cin >> n;
        if(n==0)
            break;
        cin >> q;
        for(int i=0;i<n;i++)
            cin >> a[i];
        build(0,0,n-1);
        while(q--)
        {
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            cout << query(0,0,n-1,x,y).maxFreq << endl;
        } 
    }
    
    return 0;
}