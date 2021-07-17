#include<bits/stdc++.h>
using namespace std;
 struct Node
{
    struct Node *left, *right;
    int info;
    bool lthread;
    bool rthread;
};
struct Node *insert(struct Node *root, int ikey)
{
    Node *ptr = root;
    Node *par = NULL; // Parent of key to be inserted
    while (ptr != NULL)
    {
        // If key already exists, return
        if (ikey == (ptr->info))
        {
            printf("Duplicate Key !\n");
            return root;
        }
        par = ptr; // Update parent pointer
        // Moving on left subtree.
        if (ikey < ptr->info)
        {
            if (ptr -> lthread == false)
                ptr = ptr -> left;
            else
                break;
        }
         // Moving on right subtree.
        else
        {
            if (ptr->rthread == false)
                ptr = ptr -> right;
            else
                break;
        }
    }
    // Create a new Node
    Node *tmp = new Node;
    tmp -> info = ikey;
    tmp -> lthread = true;
    tmp -> rthread = true;
    if (par == NULL)
    {
        root = tmp;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    else if (ikey < (par -> info))
    {
        tmp -> left = par -> left;
        tmp -> right = par;
        par -> lthread = false;
        par -> left = tmp;
    }
    else
    {
        tmp -> left = par;
        tmp -> right = par -> right;
        par -> rthread = false;
        par -> right = tmp;
    }
    return root;
}
// Returns inorder successor using rthread
// (Used in inorder)
struct Node *inorderSuccessor(struct Node *ptr)
{
    if (ptr -> rthread == true)
        return ptr->right;
    ptr = ptr -> right;
    while (!ptr -> lthread)
        ptr = ptr -> left;
    return ptr;
}
// Printing the threaded tree
void inorder(struct Node *root)
{
    if (root == NULL)
        printf("Tree is empty");
    struct Node *ptr = root;
    while (ptr -> lthread == false)
        ptr = ptr -> left;
    while (ptr != NULL)
    {
        printf("%d ",ptr -> info);
        ptr = inorderSuccessor(ptr);
    }
}
struct Node *inPred(struct Node *ptr)
{
    if (ptr->lthread == true)
        return ptr->left;
    ptr = ptr->left;
    while (!ptr->rthread)
        ptr = ptr->right;
    return ptr;
}
// Here 'par' is pointer to parent Node and 'ptr' is
// pointer to current Node.
struct Node *caseA(struct Node *root, struct Node *par,struct Node *ptr)
{
    // If Node to be deleted is root
    if (par == NULL)
        root = NULL;
    // If Node to be deleted is left of its parent
    else if (ptr == par->left)
    {
        par->lthread = true;
        par->left = ptr->left;
    }
    else
    {
        par->rthread = true;
        par->right = ptr->right;
    }
    free(ptr);
    return root;
}
// Here 'par' is pointer to parent Node and 'ptr' is pointer to current Node.
struct Node *caseB(struct Node *root, struct Node *par,struct Node *ptr)
{
    struct Node *child;// Initialize child
    // Node to be deleted has left child.
    if (ptr->lthread == false)
        child = ptr->left;
    // Node to be deleted has right child.
    else
        child = ptr->right;
    // Find successor and predecessor
    Node *s = inorderSuccessor(ptr);
    Node *p = inPred(ptr);
    // Node to be deleted is root Node.
    if (par == NULL)
        root = child;
    // Node is left child of its parent.
    else if (ptr == par->left)
        par->left = child;
    else
        par->right = child;
    // If ptr has left subtree.
    if (ptr->lthread == false)
        p->right = s;
    // If ptr has right subtree.
    else
            s->left = p;
    free(ptr);
    return root;
}
// Here 'par' is pointer to parent Node and 'ptr' is pointer to current Node.
struct Node *caseC(struct Node *root, struct Node *par,struct Node *ptr)
{
    // Find inorder successor and its parent.
    struct Node *parsucc = ptr;
    struct Node *succ = ptr -> right;
    // Find leftmost child of successor
    while (succ->lthread == false)
    {
        parsucc = succ;
        succ = succ -> left;
    }
    ptr->info = succ->info;
    if (succ->lthread == true && succ->rthread == true)
        root = caseA(root, parsucc, succ);
    else
        root = caseB(root, parsucc, succ);
    return root;
}
// Deletes a key from threaded BST with given root and returns new root of BST.
struct Node *delThreadedBST(struct Node* root, int dkey)
{
    // Initialize parent as NULL and ptrent
    // Node as root.
    struct Node *par = NULL, *ptr = root;
    // Set true if key is found
    int found = 0;
    // Search key in BST : find Node and its parent.
    while (ptr != NULL)
    {
        if (dkey == ptr->info)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (dkey < ptr->info)
        {
            if (ptr->lthread == false)
                ptr = ptr -> left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }
    if (found == 0)
        printf("dkey not present in tree\n");
    // Two Children
    else if (ptr->lthread == false && ptr->rthread == false)
        root = caseC(root, par, ptr);
    // Only Left Child
    else if (ptr->lthread == false)
        root = caseB(root, par, ptr);
    // Only Right Child
    else if (ptr->rthread == false)
        root = caseB(root, par, ptr);
    // No child
    else
        root = caseA(root, par, ptr);
    return root;
}
// Driver Program
int main()
{
    struct Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 17);
    root = insert(root, 13);
    root = delThreadedBST(root, 20);
    inorder(root);
    return 0;
}
