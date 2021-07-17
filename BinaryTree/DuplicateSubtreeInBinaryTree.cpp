#include <bits/stdc++.h>
using namespace std;
struct Node
{
	char data;
	struct Node *left;
	struct Node *right;
	
	Node(char x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};
struct Node* insert(struct Node* root,char data)
{
    if(root==NULL){
        root= new Node(data);
        return root;
    }
    else if(root->data<data)
    root->right=insert(root->right,data);
    else if(root->data>data)
    root->left=insert(root->left,data);
  return root;
}
struct Node* insertString(struct Node* root,string s, int *j)
{
    if((*j)>=s.length())
    return NULL;
	          if(s[*j]=='(')
	          (*j)++;
	         if(s[*j]!='('&&s[*j]!=')'){
	             
	             char n=0;
	             n = s[*j];
             (*j)++;
	          root=insert(root,n);
	          //cout<<"root->data="<<root->data<<endl;
	         // (*j)++;
	          if(s[*j]==')'){
                root->left=NULL;
              root->right=NULL;
              //cout<<"root->data="<<root->data<<endl;
              //cout<<"root->left=NULL";
              //cout<<"root->right=NULL";
              return root;
	          }
	         }
             if(s[*j]=='(')
	          (*j)++;
	          if(s[*j]==')'){
	            //  cout<<"root->data="<<root->data<<endl;
              //cout<<"root->left=NULL";
	          root->left=NULL;
	          }
              else{
                //    cout<<"root->left->parent->data="<<root->data<<endl;
	          root->left=insertString(root->left,s,j);
              }
//cout<<"right";
              while(s[*j]==')')
	          (*j)++;
	          if(s[*j]=='(')
	          (*j)++;
	          if(s[*j]==')'){
      //        cout<<"root->data="<<root->data<<endl;
        //      cout<<"root->right=NULL";
	          root->right=NULL;
	          (*j)++;
	          }
	          else{
          //    cout<<"root->right->parent->data"<<root->data<<endl;
              root->right=insertString(root->right,s,j);
	          }
return root;
}
void print(struct Node* root)
{
    if(root==NULL)
        return;
    print (root->left);
    cout<<root->data<<endl;
    print(root->right);
}
bool dupSub(Node *root);
int main() {
	//code
	int i,j,k,T ,level;
	char s[500];
	   cin>>T;
	   for(i=0;i<T;i++)
	   {
	     // cin>>level;
	      cin>>s;
	      int j=0;
	      struct Node* root=NULL;
	      root=insertString(root,s,&j);
	   
        cout<<dupSub(root)<<endl;
	  
	   }
	return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/
/*This function returns true if the tree contains 
a duplicate subtree of size 2 or more else returns false*/
set<string> st;

string func(Node* root)
{
    string s = "";
    if(!root)
        return s+'$';
    string lStr = func(root->left);
    if(lStr == "")
        return s;
    
    string rStr = func(root->right);
    if(rStr == "")
        return s;
        
    s = s+root->data+lStr+rStr;

    if(s.length()>3 && st.count(s)>0)
        return "";
    st.insert(s);
    return s;
}

bool dupSub(Node *root)
{
    //your code here
    string str = func(root);
    if(str=="")
        return 1;
    return 0;
}