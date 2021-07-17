#include<bits/stdc++.h>
using namespace std;
#define ll  long long

ll f(ll a, ll b, ll m)
{
    if(b==0)
        return 0;
    if(b%2==0)
    {
        ll x=f(a,b/2,m);
        return (x+x)%m;
    }
    else
    {
        ll x=f(a,b/2,m);
        return (x+x+a)%m;
    }
}

/* To calculate       (base^exp)mod m          using recursion
   Does not work when base,exp,n ~ 10^10 and above */
ll ModPow2(ll base, ll exp, ll m)
{
   if(exp==0)
      return 1;
   ll x=ModPow2(base,exp/2,m);
   if(exp%2==0)
       return ((x*x)%m);
   else
      return ((x*x)%m*base%m)%m;
       //ll x=ModPow2(base,exp/2,m);
}
/*               When base,exp,m ~ 10^17            */
ll ModPow3(ll base, ll exp, ll m)
{
   if(exp==0)
      return 1;
   if(exp%2==0)
   {
        ll x=ModPow3(base,exp/2,m);
        return f(x,x,m);
   }
   else
    {
        ll x=ModPow3(base,exp/2,m);
        return f(f(x,x,m),base%m,m);
       //ll x=ModPow2(base,exp/2,m);
    }
}

int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
    ll b,e,m,k;
    cin >> b >> e >> m;
    k=ModPow3(b,e,m);
    cout << k << endl;
	}
}
