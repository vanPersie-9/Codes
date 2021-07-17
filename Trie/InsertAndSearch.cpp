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
    Trie* children[size];
    bool isEnd;
};

Trie* newNode()
{
    Trie* tmp = new Trie;
    tmp->isEnd = false;
    for(int i=0;i<size;i++)
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
        tmp = tmp->children[x];
    }
    tmp->isEnd = true;
}

bool search(Trie* root, string s)
{
    Trie* tmp = root;
    for(int i=0;i<s.length();i++)
    {
        int x = s[i]-'a';
        if(!tmp->children[x])
            return false;
        tmp = tmp->children[x];
    }
    return (tmp && tmp->isEnd);
}

int32_t main()
{
    TFiOS;

    int t,n;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        Trie* root = newNode();
        for(int i=0;i<n;i++)
        {
            cin >> s;
            insert(root, s);
        }
        cin >> s;
        cout << search(root,s) << endl;
    }
}