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
        tmp=tmp->children[x];
    }
    return (tmp && tmp->isEnd);
}

bool isEmpty(Trie* root)
{
    for(int i=0;i<size;i++)
        if(root->children[i])
            return false;
    return true;
}

void printFurther(Trie* root, string s)
{
    if(root->isEnd)
        cout << s << " ";

    string prefix = s;
    for(int i=0;i<size;i++)
    {
        char c = 'a'+i;
        if(root->children[i])
            printFurther(root->children[i], prefix+c);
    }
}

int printAutoSuggestions(Trie* root, string s)
{
    Trie* tmp = root;
    for(int i=0;i<s.length();i++)
    {
        int x = s[i]-'a';
        if(!tmp->children[x])
            return 0;
        tmp=tmp->children[x];
    }
    if(tmp && tmp->isEnd)
        cout << s << " ";
    
    if(isEmpty(tmp))
        return -1;

    string prefix = s;
    for(int i=0;i<size;i++)
    {
        char c = 'a'+i;
        if(tmp->children[i])
            printFurther(tmp->children[i], prefix+c);
    }
    return 1;
}


int32_t main() 
{ 
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n;
        Trie* root = newNode();
        for(int i=0;i<n;i++)
        {
            cin >> s;
            insert(root,s);
        }
        cin >> s;
        for(int i=0;i<s.length();i++)
        {
            string tmp = s.substr(0,i+1);
            int comp = printAutoSuggestions(root, tmp);
            if(comp==0)
                cout << 0;
            cout << endl;
        }
    }
  
    return 0; 
} 