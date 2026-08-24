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

int main()
{
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int pos[] = {4, 5, 2, 6, 7, 3, 1};

    return 0;
}