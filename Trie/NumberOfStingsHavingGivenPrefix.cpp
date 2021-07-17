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

#define size 26
struct Trie
{
    int freq;
    Trie* children[size];;
    bool isEnd;
};

Trie* newNode()
{
    Trie* tmp = new Trie;
    tmp->isEnd = false;
    tmp->freq = 0;
    for(int i=0;i<size;++i)
        tmp->children[i] = NULL;
    return tmp;
}

void insert(Trie* root, string s)
{
    Trie* tmp = root;
    for(int i=0;i<s.length();i++)
    {
        int x = s[i]-'a';
        if(!tmp->children[x])
            tmp->children[x] = newNode();
        tmp->children[x]->freq++;
        tmp = tmp->children[x];
    }
    tmp->isEnd = true;
}
int ans;

bool search(Trie* root, string s)
{
    Trie* tmp =root;
    for(int i=0;i<s.length();i++)
    {
        int x = s[i]-'a';
        if(!tmp->children[x])   
            return 0;
        tmp = tmp->children[x];
    }
    ans += tmp->freq;
    return 1;
}

int32_t main()
{
    TFiOS;

    int t,n,q;
    cin >> t;
    while(t--)
    {
        cin >> n;
        string s;
        Trie* root = newNode();
        for(int i=0;i<n;i++)
        {
            cin >> s;
            insert(root, s);
        }
        cin >> q;
        while(q--)
        {
            cin >> s;
            ans=0;
            if(!search(root,s)) 
                cout << 0 << endl;
            else
            {
                cout << ans << endl;
            }
            
        }
    }
} 