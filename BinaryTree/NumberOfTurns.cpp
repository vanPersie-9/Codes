#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
int NumberOFTurn(struct Node* root, int first, int second);
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL) root = parent;
        }
        else parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')parent->left = child;
        else parent->right = child;
        m[n2]  = child;
     }
     int turn, first, second;
     cin>>first>>second;
	 if ((turn = NumberOFTurn(root, first, second) ))cout<<turn<<endl;
	 else cout<<"-1";
  }
  return 0;
}
int ans;

Node* LCA(Node* root, int a, int b)
{
    if(!root)
        return NULL;
    if(root->key==a || root->key==b)
        return root;
    Node* l = LCA(root->left,a,b);
    Node* r = LCA(root->right,a,b);
    if(l && r)
        return root;
    if(l)
        return l;
    return r; 
}

bool count(Node* root, int x, bool c)
{
    if(!root)
        return 0;
    if(root->key==x)
        return 1;
    
    if(c)
    {
        if(count(root->left,x,1))
            return 1;
        if(count(root->right,x,0))
        {
            ans++;
            return 1;
        }
    }
    else
    {
        if(count(root->right,x,0))
            return 1;
        if(count(root->left,x,1))
        {
            ans++;
            return 1;
        }
    }
    return 0;
    
}

int NumberOFTurn(struct Node* root, int a, int b)
{
    Node* lca = LCA(root, a, b);
    if(!lca)
        return -1;
    ans=0;

    if(lca->key!=a && lca->key!=b)
    {
        if(count(lca->left,a,1));
        else count(lca->right,a,0);

        if(count(lca->left,b,1));
        else count(lca->right,b,0);

        return ans+1;
    }

    if(lca->key==a)
    {
        if(count(lca->left,b,1));
        else count(lca->right,b,0);
    }
    else
    {
        if(count(lca->left,a,1));
        else count(lca->right,a,0);
    }
    return ans;
    
}