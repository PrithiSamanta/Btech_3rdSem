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

struct TreeNode *insertNode(struct TreeNode *root)
{
    int val;
    printf("Enter value to insert. Enter -1 to not insert anything.\n");

    scanf("%d", &val);

    if (val == -1)
    {
        return NULL;
    }

    struct TreeNode *newNode = createNode(val);

    printf("Enter value to insert for left subtree of %d.\n", newNode->data);
    newNode->left = insertNode(newNode->left);

    printf("Enter value to insert for right subtree of %d.\n", newNode->data);
    newNode->right = insertNode(newNode->right);

    return newNode;
}

void preOrder(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d, ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    struct TreeNode *root = NULL;
    root = insertNode(root);
    preOrder(root);
    return 0;
}