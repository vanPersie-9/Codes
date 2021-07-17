#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl "\n"
#define mp make_pair
#define MOD 1000000007


struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x)
{
    Node* tmp = new Node();
    tmp->data = x;
    tmp->right = tmp->left=NULL;
    return tmp;
}


int ind;

Node* build(int pre[], int n, int min, int max)
{
    if(ind>=n)
        return NULL;
    Node* tmp = NULL;
    int x = pre[ind];
    
    if(x>min && x<max)
    {
        tmp = newNode(x);
        ind++;
        if(ind<n)
        {
            tmp->left = build(pre, n, min, x);
            tmp->right = build(pre, n, x, max);
        }
    }
    return tmp;
}

Node* constructTree(int pre[], int n)
{
    if(!n)
        return NULL;
    ind  = 0;
    Node* root = build(pre, n, INT_MIN, INT_MAX);
    return root;
}

void printPostOrder(Node* root)
{
    if(!root)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int pre[n];
        for(int i=0;i<n;i++)
            cin >> pre[i];
        Node* root = constructTree(pre, n);
        printPostOrder(root);
        cout << endl;
    }
}