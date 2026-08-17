#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    char c;
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

int setBalanced(struct TreeNode *root)
{
    // int length = 0;
    if (root == NULL)
    {
        return 0;
    }
    int left = 0, right = 0;
    left = left + setBalanced(root->left);
    right = right + setBalanced(root->right);

    if (left == right + 1)
    {
        root->c = 'L';
    }
    else if (left + 1 == right)
    {
        root->c = 'R';
    }
    else if (left == right)
    {
        root->c = 'B';
    }
    else
    {
        root->c = 'C';
    }
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

void preOrderWithProperty(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d is %c, ", root->data, root->c);
    preOrderWithProperty(root->left);
    preOrderWithProperty(root->right);
}

int main()
{
    struct TreeNode *root = NULL;
    root = insertNode(root);
    setBalanced(root);
    preOrderWithProperty(root);
    return 0;
}