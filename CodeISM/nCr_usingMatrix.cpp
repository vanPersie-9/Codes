#include<bits/stdc++.h>
using namespace std;
long long int c[100][100];
void f(int n,int r,int m)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==j || j==0)
                c[i][j]=1;
            else
                c[i][j]=(c[i-1][j] + c[i-1][j-1])%m;
        }
    }
}
int main()
{
    int n,m,r;
    cin >> n>>r>>m;
    f(n,r,m);
    cout << c[n][r];
}
