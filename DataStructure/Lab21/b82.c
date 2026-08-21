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
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
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

int getLeftMost(struct TreeNode *root)
{
    if (root->left == NULL)
    {
        return root->data;
    }
    getLeftMost(root->left);
}

int getRightMost(struct TreeNode *root)
{
    if (root->right == NULL)
    {
        return root->data;
    }
    getRightMost(root->right);
}

void printLeftMostRightMost(struct TreeNode *root)
{
    int left = getLeftMost(root);
    int right = getRightMost(root);
    printf("The left most node is %d.The right most node is %d", left, right);
}
void preOrder(struct TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d, ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    struct TreeNode *root = NULL;
    root = insertNode(root, 4);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 9);
    root = insertNode(root, 3);
    root = insertNode(root, 7);

    preOrder(root);
    printLeftMostRightMost(root);

    return 0;
}