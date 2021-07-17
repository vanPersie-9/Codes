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
string ans;

void calcLCP(Trie* root)
{
    Trie* tmp = root;
    int ind=-1;
    int c = 0;
    for(int i=0;i<size;i++)
    {
        if(tmp->children[i])
        {
            c++;
            ind = i;
        }
    }
    if(c!=1 || root->isEnd)
        return;
    char ch = 'a'+ind;
    ans.pb(ch);
    calcLCP(root->children[ind]);
}

string commonPrefix(string arr[], int n)
{
    Trie* root = newNode();
    for(int i=0;i<n;i++)
        insert(root, arr[i]);
    
    ans = "";
    calcLCP(root);
    return ans;
}

int32_t main() 
{ 
    TFiOS;
    
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        string arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        
        string ansStr = commonPrefix(arr, n); 
        if (ansStr.length()) 
            cout << ansStr << endl; 
        else
            cout << -1 << endl; 
    }
    return (0); 
}