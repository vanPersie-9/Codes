#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long i,j,k,n,t,flag,c=0,p=0,l=100000000,w=0;
    vector<int> b;
    k=l;
    l=sqrt(l)+1;
    bool a[l];
    memset(a,true, sizeof(a));
    for(i=2;i<l;i++)
    {
        if(a[i]==true)
        {
            for(j=i*i;j<l;j+=i)
                a[j]=false;
            b.push_back(i);
            w++;
        }
    }
    vector<int> c1;
    long long h,o,f;
    long long low=l;
    long long high=2*l;
    while(low<k)
    {
        bool mark[high-low+1];
        memset(mark,true,sizeof(mark));
        for(i=0;i<w;i++)
        {
            f=low/b[i];
            f=f*b[i];
            if(f<low)
            f+=b[i];
            for(j=f;j<high;j+=b[i])
                mark[j-low]=false;
        }
        for(i=low;i<high;i++)
        {
            if(mark[i-low]==true)
            {
                c1.push_back(i);
            }
        }
        low+=l;
        high=high+l;
        if(high>=k)
        high=k;
    }
    vector<int> d1;
    for(i=0;i<b.size();i++)
        d1.push_back(b[i]);
    for(i=0;i<c1.size();i++)
        d1.push_back(c1[i]);
    int q;
    cin>>q;
    for(i=0;i<q;i++)
    {
        cin>>k;
        cout<<d1[k-1]<<endl;
    }
    return 0;
}
