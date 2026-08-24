#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

int preIndex = 0;

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

struct TreeNode *createBinaryTree(int *preOrder, int *inOrder, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    struct TreeNode *root = createNode(preOrder[preIndex++]);

    int inPos = getInOrderPos(inOrder, root->data, start, end);

    root->left = createBinaryTree(preOrder, inOrder, start, inPos - 1);

    root->right = createBinaryTree(preOrder, inOrder, inPos + 1, end);

    return root;
}

void postOrder(struct TreeNode *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d, ", root->data);
    }
}

int main()
{
    int in[] = {4, 2, 5, 1, 6, 3, 7};
    int pre[] = {1, 2, 4, 5, 3, 6, 7};

    struct TreeNode *root = NULL;

    root = createBinaryTree(pre, in, 0, 6);

    postOrder(root);

    return 0;
}