#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll spf[1000000+1];
void FactorSieve(ll n)
{
    spf[1]=1;
    bool p[n+1];
    memset(p,false,sizeof(p));
    for(ll i=2;i<1000000+1;i++)
        spf[i]=i;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(!p[i])
        {
            spf[i]=i;
            for(int j=i*i;j<=n;j+=i)
            {
                if(spf[j]==j)
                    spf[j]=i;
                p[j]=true;
            }
        }
    }
}
int main()
{
    ll x;
    cin >> x;
    FactorSieve(1000000);
    vector<int> f;
    while(x!=1)
    {
        f.push_back(spf[x]);
        x=x/spf[x];
    }
    cout << f[0] << endl;
    for(int i=1;i<f.size();i++)
         if(f[i]!=f[i-1])
            cout << f[i] << "\n";
}
