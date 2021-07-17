#include<bits/stdc++.h>
using namespace std;
int ETF(int n)
{
    int c=0;
    for(int i=0;i<=n;i++)
    {
        if(__gcd(i,n)==1)
            c++;
    }
    return c;
}
int main()
{
    int number;
    cin >> number;
    //cout << ETF(n);
    int maxPrime=1;
        while(number%2==0)
        {
            number/=2;
            maxPrime = 2;
        }
        for(int i=3; i  <= number ; i+=2 )
        {
            while(number%i == 0)
            {
                maxPrime = i;
                number/=i;
            }
        }
        cout << maxPrime;
}
