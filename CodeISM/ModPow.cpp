#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int MOD = 998244353;
/* To calculate       (base^exp)mod m          using iteration */
ll ModPow(ll base, ll exp, ll m)
{
    ll r=1,p;
    base %= m;
    //p=base;
    while(exp)
    {
        if(exp&1)
            r=(r*base)%m;
        exp=exp>>1;
        base=(base*base)%m;
    }
    return r;
}
int main()
{
    /*int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
    ll b,e,m,k;
    cin >> b >> e >> m;
    k=ModPow(b,e,m);
    cout << i+1<<". "<< k << endl;
	}***/
	cout << (ModPow(2,100005,MOD))%MOD;
}
