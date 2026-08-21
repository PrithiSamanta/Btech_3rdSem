#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)(malloc(sizeof(struct TreeNode)));
    newNode->data = val;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

struct TreeNode *insertNode(struct TreeNode *root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }
    if (root->data < val)
    {
        root->right = insertNode(root->right, val);
    }
    else if (root->data > val)
    {
        root->left = insertNode(root->left, val);
    }
    return root;
}

void search(struct TreeNode *root,int val){
    if (root==NULL)
    {
        printf("Tree is empty/node not found");
        return;
    }
    if (root->data < val)
    {
        search(root->right,val);
    }
    else if (root->data > val)
    {
        search(root->left,val);
    }
    else if (root->data==val)
    {
        printf("Node found");
        return;
    }
    
}

void preOrder(struct TreeNode *root){
    if (root!=NULL)
    {
        printf("%d, ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    
}

int main(){
    struct TreeNode *root = NULL;
    root=insertNode(root,23);
    root=insertNode(root,3);
    root=insertNode(root,12);
    root=insertNode(root,2);
    preOrder(root);
    return 0;
}