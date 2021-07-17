#include<bits/stdc++.h>
using namespace std;
// A binary Tree node
struct node
{
	int data;
	struct node *left;
	struct node *right;
	
	node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
int counter=0;
int target=0;
struct node *ptr=NULL;
void printkdistanceNodeDown(node *root, int k);
int printkdistanceNode(node* root, node* target , int k);
 void insert(struct node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->data==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new node(n2);
                    break;
          case 'R': root->right=new node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
 void Inorder(struct node* root)
{
    if(counter==0)
    {
        cin>>target;
        counter++;
    }
    if(root==NULL)
        return ;
    Inorder(root->left);
    if(root->data==target)
         ptr=root;
    Inorder(root->right);
}
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new node(n1);
            switch(lr){
                    case 'L': root->left=new node(n2);
                    break;
                    case 'R': root->right=new node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
    Inorder(root);
    node * target =ptr;
    cin>>k;
    printkdistanceNode(root, target, k);
    cout<<endl;
    counter=0;
    }
    return 0;
}

void printkdistanceNodeDown(node* root, int k)
{
    if(!root || k<0)
        return;
    if(k==0)
    {
        cout << root->data << " ";
        return;
    }
    printkdistanceNodeDown(root->left, k-1);
    printkdistanceNodeDown(root->right, k-1);
}

int printkdistanceNode(node* root, node* target, int k)
{
    if(!root)
        return -1;

    if(root==target)
    {
        printkdistanceNodeDown(root, k);
        return 0;
    }

    int dl = printkdistanceNode(root->left, target, k);
    if(dl!=-1)  // dl is the distance of target from left child of root
    {
        if(dl+1==k)
            cout << root->data << " ";
        else
            printkdistanceNodeDown(root->right, k-dl-2);
        
        return 1+dl;
    }

    int dr = printkdistanceNode(root->right, target, k);
    if(dr!=-1)
    {
        if(dr+1==k)
            cout << root->data << " ";
        else
            printkdistanceNodeDown(root->left, k-dr-2);
        
        return 1+dr;
    }

    return -1;
}