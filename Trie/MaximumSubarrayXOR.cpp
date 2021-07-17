#include <bits/stdc++.h>
using namespace std;
#define TFiOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define int ll
#define pb push_back
#define endl "\n"
#define mp make_pair
#define ff first
#define ss second
const int MOD = 1e9+7;

#define size 64
struct Trie
{
    int val;
    Trie* bit[2];
};

Trie* newNode()
{
    Trie* tmp = new Trie;
    tmp->val = 0;
    tmp->bit[0] = tmp->bit[1] = NULL;
    return tmp;
}

void insert(Trie* root, int val)
{
    Trie* tmp = root;
    for(int i=size-1;i>=0;i--)
    {
        bool x = val & (1LL << i);
        if(!tmp->bit[x])
            tmp->bit[x] = newNode();
        tmp = tmp->bit[x];
    }
    tmp->val = val;
}

int query(Trie* root, int val)
{
    Trie* tmp = root;
    for(int i=size-1;i>=0;i--)
    {
        bool x = val & (1LL << i);
        if(tmp->bit[1-x])
            tmp = tmp->bit[1-x];
        else if(tmp->bit[x])
            tmp = tmp->bit[x];
    }
    return (val^(tmp->val));
}
int ans = -1;
int xorVal = 0;

int32_t main()
{
    TFiOS

    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int x;
        ans = -1e10;
        xorVal = 0;
        Trie* root = newNode();
        for(int i=0;i<n;i++)
        {
            cin >> x;
            xorVal ^=x;
            ans = max(ans, query(root,xorVal));

            insert(root, xorVal);
        }
        cout << ans << endl;
    }
}