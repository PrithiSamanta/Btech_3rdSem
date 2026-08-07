#include <stdio.h>
#include <stdlib.h>

#define size 100
int queue[size];
int front = -1, rear = -1;

void insFront(int val)
{
    if (front == 0)
    {
        printf("Can't insert.");
        return;
    }
    if (front == -1)
    {
        queue[++front] = val;
        rear = front;
    }
    else
    {
        queue[--front] = val;
    }
}

void insRear(int val)
{
    if (rear == size - 1)
    {
        printf("Can't insert.");
        return;
    }
    if (rear == -1)
    {
        queue[++rear] = val;
        front = rear;
    }
    else
    {
        queue[++rear] = val;
    }
}

void delFront()
{
    if (front == -1)
    {
        printf("The queue is empty");
    }
    if (front == rear)
    {
        int y = queue[front];
        front = rear = -1;
        printf("The deleted element is %d\n", y);
    }
    else
    {
        int y = queue[front++];
        printf("The deleted element is %d\n", y);
    }
}

void delRear()
{
    if (front == -1)
    {
        printf("The queue is empty");
    }
    if (front == rear)
    {
        int y = queue[rear];
        front = rear = -1;
        printf("The deleted element is %d\n", y);
    }
    else
    {
        int y = queue[--rear];
        printf("The deleted element is %d\n", y);
    }
}

void display(){
    if (front==-1)
    {
        printf("The queue is empty.\n");
        return;
    }
    int temp=front;
    while (temp!=rear)
    {
        printf("%d, ",queue[temp++]);
    }
    printf("%d\n",queue[rear]);
}

void main()
{
    display();
insFront(4);
    insRear(2);
    display();
}