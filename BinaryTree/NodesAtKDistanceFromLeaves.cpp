#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 10000
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
int printKDistantfromLeaf(Node* node, int k);
 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
    cin>>k;
    cout<<printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}

#define pb push_back
map<int, int> m;

void func(Node* root, vector<int> &anc, int* cnt, int k)
{
    if(root==NULL)
        return;
    //cout << root->key << "-+-+-\n";
    if(root->left==NULL && root->right==NULL)
    {
        //cout << root->key << "+++++ " << anc.size() << endl ;
        if((int)anc.size()>=k+1)
        {
            int x = (int)anc.size()-k-1;
            int tmp = anc[x];
            //cout << "---->" << tmp << " " << m[tmp] << endl;
            if(m[tmp]==0)
            {
                m[tmp]=1;
                (*(cnt))++;
                //cout << "HERE\n";
            }
        }
        return;
    }
    if(root->left!=NULL)
    {
        anc.pb(root->left->key);
        func(root->left, anc, cnt, k);
        anc.pop_back();
    }
    if(root->right!=NULL)
    {
        anc.pb(root->right->key);
        func(root->right, anc, cnt, k);
        anc.pop_back();
    }
    return;
}

int printKDistantfromLeaf(Node* root, int k)
{
	//Add your code here.
	if(!root)
	    return 0;
    m.clear();
    vector<int> anc;
    int cnt=0;
    anc.pb(root->key);
    func(root, anc, &cnt, k);
    //cout << " ---- " << cnt << endl;
    return cnt;
}