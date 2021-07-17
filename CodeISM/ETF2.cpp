#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll phi(ll n)
{
    ll result = n;
    for (int p=2; p*p<=n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
int main()
{
    ll n;
    cin >> n;
    cout << phi(n);
}
