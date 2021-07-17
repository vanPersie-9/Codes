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
const int N = 1e3;
bool mat[N][N]; // i is ancestor of j => mat[i][j] = 1


struct Node 
{ 
    int data; 
    Node *left, *right; 
};

int build(Node* root, vector<int> &anc)
{
    if(root==NULL)
        return 0;
    
    int x = root->data;
    for(int i=0;i<(int)anc.size();i++)
        mat[anc[i]][x] = 1;

    anc.pb(x);
    int l = build(root->left, anc);
    int r = build(root->right, anc);
    anc.pop_back();

    return l+r+1;

}
void ancestorMatrix(Node* root)
{
    vector<int> anc;

    int n = build(root, anc);
    cout << "---> " << n << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

Node* newnode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
/* Driver program to test above functions*/
int32_t main() 
{ 
    /* Construct the following binary tree 
                5 
              /   \ 
            1      2 
          /  \    / 
         0    4  3    */
    Node *root        = newnode(5); 
    root->left        = newnode(1); 
    root->right       = newnode(2); 
    root->left->left  = newnode(0); 
    root->left->right = newnode(4); 
    root->right->left = newnode(3); 
  
    ancestorMatrix(root); 
  
    return 0; 
} 