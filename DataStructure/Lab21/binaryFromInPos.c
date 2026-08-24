#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

int postIndex = 6;

struct TreeNode *createNode(int val)
{
    struct TreeNode *newNode = (struct TreeNode *)(malloc(sizeof(struct TreeNode)));
    newNode->data = val;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

int getInOrderPos(int *in, int val, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == val)
        {
            return i;
        }
    }
    return -1;
}

struct TreeNode *createBinaryTree(int *posOrder, int *inOrder, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    struct TreeNode *root = createNode(posOrder[postIndex--]);

    int inPos = getInOrderPos(inOrder, root->data, start, end);

    root->right = createBinaryTree(posOrder, inOrder, inPos + 1, end);

    root->left = createBinaryTree(posOrder, inOrder, start, inPos - 1);

    return root;
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
    int in[] = {4, 2, 5, 1, 6, 3, 7};
    int pos[] = {4, 5, 2, 6, 7, 3, 1};

    struct TreeNode *root = NULL;

    root = createBinaryTree(pos, in, 0, 6);

    preOrder(root);

    return 0;
}