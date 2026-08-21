#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBook
{
    char name[100];
    char phNo[10];
    struct PhoneBook *left;
    struct PhoneBook *right;
};

struct PhoneBook *createEntry(char *n, char *p)
{

    struct PhoneBook *newEntry = (struct PhoneBook *)malloc(sizeof(struct PhoneBook));
    strcpy(newEntry->name, n);
    strcpy(newEntry->phNo, p);
    newEntry->right = NULL;
    newEntry->left = NULL;
}

struct PhoneBook *addEntryInPlace(struct PhoneBook *root, char *n, char *p)
{

    if (root == NULL)
    {
        return createEntry(n, p);
    }
    else if (strcmp(root->name, n) > 0)
    {
        root->left = addEntryInPlace(root->left, n, p);
    }
    else if (strcmp(root->name, n) < 0)
    {
        root->right = addEntryInPlace(root->right, n, p);
    }
    else if (strcmp(root->name, n) == 0)
    {
        printf("The name already exist give another name : ");
        char newName[100];
        scanf("%s", newName);

        root = addEntryInPlace(root, newName, p);
    }
    return root;
}
struct PhoneBook *addEntry(struct PhoneBook *root)
{
    char n[100], p[10];
    printf("Enter name : ");
    scanf("%s", n);
    printf("Enter phone number : ");
    scanf("%s", p);

    return addEntryInPlace(root, n, p);
}

void searchNum(struct PhoneBook *root,char *n){
    if (root==NULL)
    {
        printf("Phone number doesn't exist.");
        return;
    }
    else if (strcmp(root->name,n)>0)
    {
        searchNum(root->left,n);
    }
    else if (strcmp(root->name,n)<0)
    {
        searchNum(root->right,n);
    }
    else if(strcmp(root->name,n)==0){
        printf("%s - %s\n", root->name, root->phNo);
    }
}

void numTosearch(struct PhoneBook *root){
    printf("Enter the name whose phone number to search : ");
    char n[100];
    scanf("%s",n);

    searchNum(root,n);
}

void displayAscending(struct PhoneBook *root)
{
    if (root != NULL)
    {
        displayAscending(root->left);
        printf("%s - %s\n", root->name, root->phNo);
        displayAscending(root->right);
    }
}

int main()
{
    struct PhoneBook *root = NULL;
    root = addEntry(root);
    
    // root=addEntry(root);/
    // addEntry(root);
    displayAscending(root);
    return 0;
}