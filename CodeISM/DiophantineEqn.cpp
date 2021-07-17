#include<bits/stdc++.h>
using namespace std;
int x,y;
int exgcd(int a,int b)
{
    if(!b)
    {
        y=0;
        x=1;
        return a;
    }
    int g=exgcd(b,a%b);
    int temp=x;
    x=y;
    y=temp-(a/b)*y;
    return g;
}
int main()
{
    cout << "enter values of a , b & c :\n";
    int a,b,c;
    cin >> a >> b >> c;
    int g=exgcd(a,b);
    int k=c/g;
    for(int i=0;i<10;i++)
    {
      cout << x*k-i*b << "    " << y*k+i*a << "\n";
    }
}
