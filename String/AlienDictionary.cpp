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

vector<int> st;
void topoSort(vector<int> adj[], int s, vector<bool> &vis)
{
    vis[s]=1;
    for(int i=0;i<(int)adj[s].size();i++)
        if(!vis[adj[s][i]])
            topoSort(adj,adj[s][i],vis);
    st.pb(s);
}
string printOrder(string dict[], int n, int k)
{
    vector<int> adj[k];
    int s = dict[0][0]-'a';
    for(int i=0;i<n-1;i++)
    {
        string s1,s2;
        s1 = dict[i];
        s2 = dict[i+1];
        for(int i=0; i<min(s1.length(), s2.length()); ++i)
        {
            if(s1[i]!=s2[i])
            {
                adj[s1[i]-'a'].pb(s2[i]-'a');
                break;
            }
        }
    }
    vector<bool> vis(k, false);
    st.clear();
    for(int i=0;i<k;i++)
        if(!vis[i])
            topoSort(adj, i, vis);
    string ans = "";
    for(int i=(int)st.size()-1;i>=0;i--)
        ans.pb(st[i]+'a');
    return ans;
}

int32_t main()
{
    TFiOS;

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        string dict[n];
        for(int i=0;i<n;i++)
            cin >> dict[i];
        cout << printOrder(dict, n , k) << endl;
    }
}