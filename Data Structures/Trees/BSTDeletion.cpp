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
node* searchn(node* r,int x)
{
    if(r==NULL)
        return NULL;
    if(r->data==x)
        return r;
    else if(r->data>x)
        return searchn(r->left,x);
    else
        return searchn(r->right,x);
}
node* parent(node* r,int x)
{
    if(r->data==x)
        return NULL;
    if(r->left->data==x || r->right->data==x)
        return r;
    else if(x<r->data)
        return parent(r->left,x);
    else
        return parent(r->right,x);
}
node* case1(node* r,node* n,node* p)           // When node has 1 child
{
    node* child = (n->left!=NULL)? n->left : n->right;
    if(p!=NULL)
    {
        if(p->left==n)
            p->left=child;
        else
            p->right=child;
    }
    else
        r=child;
    return r;
}
node* case2(node* r,node* n,node* p)           // When node has 2 children
{
    node* s=n->right;
    node* ps=n;
    while(s->left!=NULL)                        // searching inorder successor
    {
         ps=s;
         s=s->left;
    }
    r=case1(r,s,ps);
    if(p!=NULL)
    {
        if(p->left==n)
            p->left=s;
        else
            p->right=s;
    }
    else
        r=s;
    s->left=n->left;                             // attaching children
    s->right=n->right;
    return r;
}
node* removen(node* r,int x)
{
    node* n=searchn(r,x);
    if(n==NULL)
    {
        cout << "ERROR 404\n";
        return r;
    }
    node* p=parent(r,x);
    if(n->left!=NULL && n->right!=NULL)
        r=case2(r,n,p);
    else
        r=case1(r,n,p);
    return r;
}
int main()
{
    node* root=NULL;
    node* root2=NULL;
    int a[]={45,39,56,54,78,55};
    int i;
    for(i=0;i<5;i++)
    {
        root=insertAsBST(root,a[i]);
    }
    cout << "\nBST :\n";
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    root=removen(root,54);
    cout << "\nBST :\n";
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
}
