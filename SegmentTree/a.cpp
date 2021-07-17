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
 
const int N = 2e5+5;
map<vector<pair<int,int> >, int >  avail;
vector<bool> prime(N,false);
vector<int> s(N);
 
void sieve(int n=N) 
{  
    for (int i=2; i<=N; i+=2) 
        s[i] = 2; 
    for (int i=3; i<=N; i+=2) 
    { 
        if (prime[i] == false) 
        { 
            s[i] = i;  
            for (int j=i; j*i<=N; j+=2) 
            { 
                if (prime[i*j] == false) 
                { 
                    prime[i*j] = true;  
                    s[i*j] = i; 
                } 
            } 
        } 
    } 
} 
  
pair<vector<pair<int,int> >, vector<pair<int,int> > > pF(int n, int k) 
{ 
    vector<pair<int,int> > v, invV;
    int curr = s[n];  // Current prime factor of N 
    int cnt = 1;   // Power of current prime factor 
    while (n > 1) 
    { 
        n /= s[n];  
        if (curr == s[n]) 
        { 
            cnt++; 
            continue; 
        } 
        cnt = cnt%k;
        if(cnt!=0)
        {
            v.pb(mp(curr,cnt));
            invV.pb(mp(curr,k-cnt));
        }
        curr = s[n]; 
        cnt = 1; 
    } 
    return mp(v,invV);
}
 
int32_t main()
{
    TFiOS
 
    sieve();
    int n,k;
    cin >> n >> k;
    int a[n+1];
    for(int i=1;i<=n;i++)   
        cin >> a[i];
    int c=0;
    for(int i=1;i<=n;i++)
    {
        pair<vector<pair<int,int> >, vector<pair<int,int> > > pr = pF(a[i],k);
        vector<pair<int,int> > v = pr.ff;
        vector<pair<int,int> > invV = pr.ss;
        //req[invV]++;
        if(v.size()!=0)
            avail[v]++;
        else
            c++;
    }
    //cout << "+++ " << c << endl;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        vector<pair<int,int> > invV = pF(a[i],k).ss;
        vector<pair<int,int> > v = pF(a[i],k).ff;
        if(invV.size()!=0)
        {
            ans+=avail[invV];
            if(v==invV)
                ans--;
        }
        else
            continue;
        //cout << ans << endl;
    }
    cout << ans/2 + (c*(c-1))/2;
    return 0;
}