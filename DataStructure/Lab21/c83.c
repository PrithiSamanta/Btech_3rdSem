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

    return newEntry;
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

void searchNum(struct PhoneBook *root, char *n)
{
    if (root == NULL)
    {
        printf("Phone number doesn't exist.");
        return;
    }
    else if (strcmp(root->name, n) > 0)
    {
        searchNum(root->left, n);
    }
    else if (strcmp(root->name, n) < 0)
    {
        searchNum(root->right, n);
    }
    else if (strcmp(root->name, n) == 0)
    {
        printf("%s - %s\n", root->name, root->phNo);
    }
}

void numTosearch(struct PhoneBook *root)
{
    printf("Enter the name whose phone number to search : ");
    char n[100];
    scanf("%s", n);

    searchNum(root, n);
}

struct PhoneBook *deleteNum(struct PhoneBook *root, char *n)
{
    if (root == NULL)
    {
        printf("Phone number doesn't exist.");
        return NULL;
    }
    else if (strcmp(root->name, n) > 0)
    {
        root->left = deleteNum(root->left, n);
    }
    else if (strcmp(root->name, n) < 0)
    {
        root->right = deleteNum(root->right, n);
    }
    else if (strcmp(root->name, n) == 0)
    {

        if (root->left == NULL)
        {
            struct PhoneBook *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct PhoneBook *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct PhoneBook *succ = root->right;
            while (succ->left != NULL)
            {
                succ = succ->left;
            }
            strcpy(root->name, succ->name);
            strcpy(root->phNo, succ->phNo);

            root->right = deleteNum(root->right, succ->name);
        }
    }
    return root;
}

struct PhoneBook *numToDelete(struct PhoneBook *root)
{
    printf("Enter the name which entry to be deleted : ");
    char n[100];
    scanf("%s", n);

    return deleteNum(root, n);
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

    while (1)
    {
        printf("What you want to do :\n");
        printf("1. Add a phone book record:\n");
        printf("2. Remove entry from phone book:\n");
        printf("3. Search phone number :\n");
        printf("4. List all entries in ascending order of name  :\n");
        printf("-1. To end the loop.\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            root = addEntry(root);
            break;
        }
        case 2:
        {
            root = numToDelete(root);
            break;
        }
        case 3:
        {
            numTosearch(root);
            break;
        }
        case 4:
        {
            if (root == NULL)
                printf("Phone Book is empty.\n");
            else
                displayAscending(root);
            break;
        }
        case -1:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}