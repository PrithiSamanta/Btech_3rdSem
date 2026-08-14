#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isSame(struct TreeNode *root1, struct TreeNode *root2)
{
    if (root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }
    return root1->data == root2->data &&
           isSame(root1->right, root2->right) &&
           isSame(root1->left, root2->left);
}

struct TreeNode *insertNode(struct TreeNode *root)
{
    int val;
    printf("Enter value to insert. Enter -1 to not insert anything.\n");
    
}

int main(){
    struct TreeNode *root1=NULL;
    root1=insertNode(root1,12);
    root1=insertNode(root1,23);
    root1=insertNode(root1,2);
    root1=insertNode(root1,3);

    struct TreeNode *root2=NULL;
    root2=insertNode(root2,12);
    root2=insertNode(root2,23);
    root2=insertNode(root2,2);
    root2=insertNode(root2,4);

    printf("%s",isSame(root1,root2)?"Given trees are same.":"Given trees are not same.");
    return 0;
}