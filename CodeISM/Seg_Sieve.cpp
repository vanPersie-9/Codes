#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Seg_Sieve(ll n, ll m)
{
    int x=(int)(sqrt(m));
    cout << x << "***************";
    bool p[x+1];
    memset(p,false,sizeof(p));
    for(int i=2;i<=sqrt(x);i++)//i<=x
    {
        if(!p[i])
        {
           for(int j=i*i;j<=x;j+=i)
               p[j]=true;
        }
    }
    cout << x << "***************";
    vector<int> v;
    for(int i=2;i<=x;i++)
    {
      if(p[i]==false)
          {
            v.push_back(i);
          }
    }
    cout << v.size() << "***************";
    bool IsCo[m-n+1];
    memset(IsCo,false,sizeof(IsCo));
    for(int i=0;i<v.size();i++)
    {
       ll k=n/v[i];
       ll l=k*v[i];
       if(l<n) l+=v[i];      //Finding the min. no. that is a multiple of v[i].
       for(int j=l;j<=m;j+=v[i])
       {
           if(j==v[i])
            IsCo[j-n]=false;
           else
            IsCo[j-n]=true;
       }
    cout << x << "***************";
    }
    for(int i=0;i<sizeof(IsCo);i++)
    {

        if(IsCo[i]==false)
        {
            if(n+i==1)
                continue;
            cout << n+i << endl;

        }
    }
}

int main() {

	// your code here
	int t;
	cin >> t;
    for(int z=0;z<t;z++)
    {
     ll a,b;
     cin >> a >> b;
     Seg_Sieve(a,b);
    }
	return 0;
}
