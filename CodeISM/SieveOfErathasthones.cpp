#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> v;
bool p[30000001];
void SieveOfErathasthones(ll n)
{

    memset(p,false,sizeof(p)); // false implies a prime number
    for(int i=2;i<=sqrt(n);i++)
        if(!p[i])
           for(int j=i*i;j<=n;j+=i)
               p[j]=true;
    for(int i=2;i<=n;i++)
        if(!p[i])
            v.push_back(i);
}
int main()
{
    SieveOfErathasthones(333);
    cout << v.size() << endl;
    for(int i=0;i<v.size();i++)
            cout << v[i] << ",";
    cout << __gcd(437,779);
}
