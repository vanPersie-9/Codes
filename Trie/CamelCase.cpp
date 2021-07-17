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
map<string, vector<string> > m;
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
        int x = s[i]-'A';
        if(!tmp->children[x])
            tmp->children[x] = newNode();
        tmp = tmp->children[x];
    }
    tmp->isEnd = true;
}

bool isEmpty(Trie* root)
{
    for(int i=0;i<size;i++)
        if(root->children[i])
            return 0;
    return 1;
}

void printFurther(Trie* root, string s)
{
    Trie* tmp = root;
    if(tmp->isEnd)
    {
        auto v = m[s];
        for(auto st:v)
            cout << st << " ";
    }

    string prefix = s;
    for(int i=0;i<size;i++)
    {
        char c = 'A'+i;
        if(root->children[i])
            printFurther(root->children[i], prefix+c);
    }
}


int CamelCase(Trie* root, string s)
{
    Trie* tmp = root;
    for(int i=0;i<s.length();i++)
    {
        int x = s[i]-'A';
        if(!tmp->children[x])
            return 0;
        tmp=tmp->children[x];
    }

    if(tmp->isEnd)
    {
        auto v = m[s];
        for(auto st:v)
            cout << st << " ";
    }

    if(isEmpty(root))
        return -1;

    string pre = s;
    for(int i=0;i<size;i++)
    {
        char c = i+'A';
        if(tmp->children[i])
            printFurther(tmp->children[i], pre+c);
    }
    return 1;
}

int32_t main()
{
    TFiOS

    int t,n;
    cin >> t;
    while(t--)
    {
        m.clear();
        Trie* root = newNode();
        cin >> n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s="";
            cin >> arr[i];
            for(int j=0;j<arr[i].length();j++)
                if(arr[i][j]>='A' && arr[i][j] <='Z')
                    s.pb(arr[i][j]);
            //cout << "++++ " << s << endl;
            m[s].pb(arr[i]);
            insert(root,s);
        }
        string s;
        cin >> s;
        int f = CamelCase(root, s);
        if(f==0)
            cout << "No match found";
        cout << endl;
    }
}