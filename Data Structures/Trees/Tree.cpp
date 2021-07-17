#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
node* create(int x)
{
    node* t=new node;
    t->data=x;
    t->left=t->right=NULL;
    return t;
}
node* insertAsBST(node* r,int x)
{
    node* t= create(x);
    if(r==NULL)
    {
        return t;
    }
    else if(x<r->data)
        r->left=insertAsBST(r->left,x);
    else
        r->right=insertAsBST(r->right,x);
    return r;
}
void inorder(node* r)
{
    if(r==NULL)
        return;
    inorder(r->left);
    cout << r->data << "  ";
    inorder(r->right);
}
void preorder(node* r)
{
    if(r==NULL)
        return;
    cout << r->data << "  " ;
    preorder(r->left);
    preorder(r->right);
}
void postorder(node* r)
{
    if(r==NULL)
        return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << "  " ;
}
int main()
{
    node* root=NULL;
    node* root2=NULL;
    int a[]={40,60,50,33,50,11,45,10,03,98};
    int i;
    for(i=0;i<10;i++)
    {
        root=insertAsBST(root,a[i]);
    }
    cout << "BST :\n";
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
}
