#include<bits/stdc++.h>
using namespace std;
#define ll long long

int arr[10000000];
vector<ll> v;
void Sieve(ll n)
{
    bool p[n+1];
    memset(p,false,sizeof(p));
    for(int i=2;i*i<=n;i++)
    {
        if(!p[i])
        {
           for(int j=i*i;j<=n;j+=i)
            p[j]=true;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(p[i]==false)
            v.push_back(i);
    }
}
ll ModPow(ll base, ll exp, ll m)
{
    ll r=1,p;
    base %= m;
    p=base;
    while(exp>0)
    {
        if(exp&1)
            r=(r*p)%m;
        exp=exp>>1;
        p=(p*p)%m;
    }
    return r;
}
ll f(ll x, ll p)
{
    ll res=0;
    while(x>0)
    {
        res+=x/p;
        x/=p;
    }
    return res;
}
ll f1(int n,int r, int m)
{
    Sieve(n);
    ll r1=1;
    for(ll i=0;i<v.size();i++)
    {
        ll e=f(n,v[i]) - f(r,v[i]) - f(n-r,v[i]);
        r1=(r1*ModPow(v[i],e,m))%m;
    }
    return r1;
}
ll lucas(ll n,ll r,ll m)
{
    ll ni=n%m;
    ll ri=r%m;
    if(r>n) return 0;
    if(r==n || r==0) return 1;
    return (lucas(n/m,r/m,m)*f1(ni,ri,m))%m;
}
int main()
{
    ll n,m,r,k;
    //cout << arr[10000009];
    cin >> n>>r>>m;
    k=lucas(n,r,m);
    cout << k;
}
