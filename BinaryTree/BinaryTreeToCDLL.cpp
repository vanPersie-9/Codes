#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
Node *bTreeToCList(Node *root);
void displayCList(Node *head)
{
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout <<endl;
	itr=itr->left;
	do{
		cout<<itr->data<<" ";
		itr=itr->left;
	}while(head!=itr);
	cout<<itr->data<<endl;
}
int main()
{
	int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     Node *root = NULL;
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
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    Node *head = bTreeToCList(root);
    displayCList(head); 
  }
    return 0;
}

void bToDLL(Node* root, Node** head_ref)
{
    // your code here
    if(root==NULL)
        return;
    bToDLL(root->right, head_ref);
    root->right = *head_ref;
    if(*head_ref!=NULL)
        (*(head_ref))->left = root;
    *head_ref = root;
    bToDLL(root->left, head_ref);
}
Node* bTreeToCList(Node* root)
{
    //add code here.
    
    Node* head_ref = NULL;
    bToDLL(root, &head_ref);
    Node* tmp = head_ref;
    
    if(tmp->right==NULL)
    {
        tmp->right=head_ref;
        tmp->left=head_ref;
        return head_ref;
    }
    while(tmp->right!=NULL)
        tmp = tmp->right;
    tmp->right=head_ref;
    head_ref->left=tmp;
    
    return head_ref;
}