#include<bits/stdc++.h>
using namespace std;
struct node{
    int v;
    node* left;
    node* right;
};
node* create(int x){
    node* t=new node();
    t->v=x;
    t->left=0;
    t->right=0;
    return t;
}
void inorder(node* r){
    if(r==0)
        return;
    inorder(r->left);
    cout<<r->v<<"  ";
    inorder(r->right);
}
node* insert(node* r,int x){
    node* t=create(x);
    if(r==0){
        return t;
    }else if(x<r->v)
        r->left=insert(r->left,x);
    else
        r->right=insert(r->right,x);
    return r;
}
// search and return address of a node
node* search(node* r,int x){
    if(r==0){
        return 0;
    }
    if(r->v==x)
        return r;
    else if(x<r->v)
        return search(r->left,x);
    else
        return search(r->right,x);
}
//return address of parent of a node
node* parent(node* r,int x){
    if(r->v==x)
        return 0;
    if(r->left->v==x  || r->right->v==x)
        return r;
    else if(x<r->v)
        return parent(r->left,x);
    else
        return parent(r->right,x);
}
// node to be deleted has 1 child
node* case1(node* r,node* n,node* p){
    node* child=(n->left!=0)?n->left:n->right;
    if(p!=0){
        if(p->left==n)
            p->left=child;
        else
            p->right=child;
    }else
        r=child;
    return r;
}
// node to be deleted ha 2 children
node* case2(node* r,node* n,node* p){
    node* s=n->right;
    node *ps=n;
    //searching in order successor
    while(s->left!=0){
        ps=s;
        s=s->left;
    }
    // deleting in order successor
    r=case1(r,s,ps);
    if(p!=0){
        if(p->left==n)
            p->left=s;
        else
            p->right=s;
    }else
        r=s;
    // attaching children
    s->left=n->left;
    s->right=n->right;
    return r;
}
node* remove(node* r,int x){
    node* n=search(r,x);
    if(n==0){
        cout<<"Error 404\n";
        return r;
    }
    node* p=parent(r,x);
    if(n->left!=0 && n->right!=0)
        r=case2(r,n,p);
    else
        r=case1(r,n,p);
    return r;
}
int main(){
    node* root=0;
    int a[]={40,60,50,33,510,11,45};
    int i;
    for(i=0;i<7;i++)
        root=insert(root,a[i]);
    cout<<"TREE\n";
    inorder(root);
    cout<<endl;
    root=remove(root,50);
    cout<<"NEW TREE \n";
    inorder(root);
    cout<<endl;
    return 0;
}
