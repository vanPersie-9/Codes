#include <bits/stdc++.h>
using namespace std;
#define TFiOS ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define int ll
#define pb push_back
#define endl '\n' 
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
const int MOD = 1e9+7;

void computeLPS(int LPS[], string pat, int l)
{
    LPS[0]=0;
    int i=1,len=0;
    while(i<l)
    {
        if(pat[i]==pat[len])
            LPS[i++] = ++len;
        else
        {
            if(len!=0)
                len = LPS[len-1];
            else
                LPS[i++]=0;
        }
    }
}

void KMP(int LPS[], string text, string pat)
{
    int n = text.length();
    int m = pat.length();

    int i=0,j=0;
    while(i<n)
    {
        if(j==m)
        {
            cout << "Pattern found at index " << i-j << endl;
            j = LPS[j-1];
        }
        if(pat[j]==text[i])
            i++, j++;
        else
        {
            if(j!=0)
                j = LPS[j-1];
            else
                i++;
        }  
    }
    if(j==m)
        cout << "Pattern found at index " << i-j << endl;
}

int32_t main()
{
    TFiOS

    string text,patern;
    cin >> patern >> text;
    int l = patern.length();
    int LPS[l];
    computeLPS(LPS, patern, l);
    for(int i:LPS)
        cout  << i << " ";
    cout << endl;
    KMP(LPS,text,patern);

    return 0;
}
