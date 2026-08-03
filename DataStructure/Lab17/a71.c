#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *link;
};

struct Node *front = NULL;

void enQueue(int val)
{
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
    newNode->info = val;
    if (front == NULL)
    {
        front = newNode;
    }
    else
    {
        struct Node *save = front;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
    }
    newNode->link = NULL;
}

int deQueue()
{
    if (front == NULL)
    {
        return -1;
    }
    else
    {
        struct Node *temp = front;
        int val = temp->info;

        if (front->link != NULL)
        {
            front = front->link;
        }
        else
        {
            front = NULL;
        }
        free(temp);
        return val;
    }
}

void display()
{
    if (front == NULL)
    {
        return;
    }
    struct Node *save = front;
    while (save != NULL)
    {
        printf("%d, ", save->info);
        save = save->link;
    }
}

int main()
{
    enQueue(2);
    enQueue(4);
    enQueue(5);
    enQueue(6);
    enQueue(8);
    display();
    deQueue();
    deQueue();
    display();
}