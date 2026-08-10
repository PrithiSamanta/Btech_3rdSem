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
        insertNode(root->right, val);
    }
}