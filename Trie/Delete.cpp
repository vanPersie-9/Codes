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

bool isEmpty(Trie* root)
{
    for(int i=0;i<size;i++)
        if(root->children[i])
            return false;
    return true;
}

Trie* deleteNode(Trie* root, string s, int depth = 0)
{
    if(!root)
        return NULL;
    if(depth == s.length())
    {
        if(root->isEnd)
            root->isEnd = false;
        if(isEmpty(root))
        {
            delete(root);
            root = NULL;
        }
        return root;
    }

    int ind = s[depth] - 'a';
    root->children[ind] = deleteNode(root->children[ind], s, depth+1);

    if(isEmpty(root) && root->isEnd==false)
    {
        delete(root);
        root = NULL;
    }
    return root;
}

int32_t main()
{
    string keys[] = { "the", "a", "there", 
                      "answer", "any", "by", 
                      "bye", "their", "hero", "heroplane",
                      "heroine" }; 
    int n = sizeof(keys) / sizeof(keys[0]); 
  
    struct Trie* root = newNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "the") ? cout << "Yes\n" : cout << "No\n"; 
    search(root, "these") ? cout << "Yes\n" : cout << "No\n"; 
  
    deleteNode(root, "heroine"); 
    search(root, "heroine") ? cout << "Yes\n" : cout << "No\n"; 
    search(root, "heroplane") ? cout << "Yes\n" : cout << "No\n"; 
    return 0; 
}