#include <stdio.h>
#include <stdlib.h>

struct PriorityQueue{
    int val;
    int priority;
};

#define size 100
struct PriorityQueue pq[size];

int front=-1,rear=-1;

void insert(int val,int prio){
    if (rear==size-1)
    {
        printf("Can't insert.");
        return;
    }
    else{
        pq[++rear].val=val;
        pq[++rear].priority=prio;
    }
    if (rear==0)
    {
        front=rear;
    }
}

void main(){
      
}