#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *first = NULL;

void insFirst(int x)
{
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
    newNode->info = x;
    newNode->link = first;
    first = newNode;
}
void dispList()
{
    if (first == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node *save = first;
    while (save != NULL)
    {
        printf("%d, ", save->info);
        save = save->link;
    }
    printf("\n");
}
void delFirst()
{
    struct Node *save = first;
    first = first->link;
    save->link = NULL;
    free(save);
}
void insLast(int x)
{
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
    newNode->info = x;
    newNode->link = NULL;
    if (first == NULL)
    {
        first = newNode;
        return;
    }
    struct Node *save = first;
    while (save->link != NULL)
    {
        save = save->link;
    }
    save->link = newNode;
}
void delLast()
{
    if (first == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node *save = first;
    struct Node *pre = save;
    while (save->link != NULL)
    {
        pre = save;
        save = save->link;
    }
    pre->link = NULL;
    free(save);
}
void delPos(int x)
{
    if (first == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node *save = first;
    struct Node *pre = save;
    int i = 0;
    while (i != x && save->link != NULL)
    {
        pre = save;
        save = save->link;
        i++;
    }
    if (i == x)
    {
        pre->link = save->link;
        save->link = NULL;
        free(save);
    }
    else
    {
        printf("The specified position could not be found.\n");
    }
}
void countNode()
{
    if (first == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    int count = 0;
    struct Node *save = first;
    while (save != NULL)
    {
        count++;
        save = save->link;
    }
    printf("There are %d node in the linked list.\n", count);
}

int main()
{
    int n;
    printf("Enter the function you want to perform :\n");
    printf("1. To insert a new node at start of linked list.\n");
    printf("2. To display the linked list.\n");
    printf("3. To delete a first node of linked list.\n");
    printf("4. To insert a new node at end of linked list.\n");
    printf("5. To delete a last node of linked list.\n");
    printf("6. To delete a node from specific position of linked list.\n");
    printf("7. To count the number of nodes in the linked list.\n");
    printf("-1. To end the program.\n");
    scanf("%d", &n);
    while (n != -1)
    {

        switch (n)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            int x;
            scanf("%d", &x);
            insFirst(x);
            break;
        case 2:
            dispList();
            break;
        case 3:
            delFirst();
            break;
        case 4:
            printf("Enter the value to be inserted: ");
            int y;
            scanf("%d", &y);
            insLast(y);
            break;
        case 5:
            delLast();
            break;

        case 6:
            printf("Enter the position to be deleted : ");
            int z;
            scanf("%d", &z);
            delPos(z);
            break;
        case 7:
            countNode();
            break;
        default:
            break;
        }

        printf("Enter the function you want to perform :\n");
        printf("1. To insert a new node at start of linked list.\n");
        printf("2. To display the linked list.\n");
        printf("3. To delete a first node of linked list.\n");
        printf("4. To insert a new node at end of linked list.\n");
        printf("5. To delete a last node of linked list.\n");
        printf("6. To delete a node from specific position of linked list.\n");
        printf("7. To count the number of nodes in the linked list.\n");
        printf("-1. To end the program.\n");
        scanf("%d", &n);
    }

    return 0;
}
