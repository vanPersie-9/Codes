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
int ans;
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
        tmp =tmp->children[x];
    }
    tmp->isEnd = true;
}

bool isEmpty(Trie* root)
{
    for(int i=0;i<size;i++)
        if(root->children[i])
            return false;
    return 1;
}

int countDistinctSubstring(string s);
int countNodes(Trie* root)
{
    if(!root)
        return 0;
    Trie* tmp = root;
    int c = 0; 
    for(int i=0;i<size;i++)
    {
        if(tmp->children[i])
            c+=countNodes(tmp->children[i]);
    }
    return 1+c;
}


int32_t main()
{
    int t,l,i,j;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        cout << countDistinctSubstring(s) << endl;
    }
}

int countDistinctSubstring(string s)
{
    if(s=="")
        return 0;
    Trie* root = newNode();
    for(int i=0;i<s.length();i++)
    {
        string suff = s.substr(i,s.length()-i);
        insert(root, suff);
    }
    ans=countNodes(root);
    return ans;
}

