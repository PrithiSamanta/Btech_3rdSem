#include <stdio.h>


#define size 5

int front = -1;
int rear = -1;

int queue[size];

void enQueue(int val)
{
    if ((rear+1) % size ==front)
    {
        printf("Queue Overflow");
        return;
    }
    rear = (rear+ 1)%size;
    queue[rear] = val;
    if (front == -1)
    {
        front = 0;
        return;
    }
}

int deQueue()
{
    if (front == -1)
    {
        printf("Queue Underflow");
        return -1;
    }
    int y = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front+1)%size;
    }
    return y;
}

void display()
{
    int i = front;
    while (i != rear)
    {
        printf("%d, ", queue[i]);
        i=(i+1)%size;
    }
    printf("%d",queue[rear]);
}

int main()
{
    enQueue(1);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    enQueue(6);
    deQueue();
    enQueue(6);
    display();
}