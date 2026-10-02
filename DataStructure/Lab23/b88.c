#include <stdio.h>
#define size 20
struct Dict{
    int key;

    int value;
};

struct Dict hashmap[size];

void init(){
    for (int i = 0; i < size ; i++)
    {
        hashmap[i].key=-1;
    }
    
}

int hasfunction(int key){
    return key%size;
}

void put(int key,int value){
    int idx=hasfunction(key);

    while (hashmap[idx].key!=-1 && hashmap[idx].key!=key)
    {
        idx=(idx+1)%size;
    }
    hashmap[idx].key=key;
    hashmap[idx].value=value;
}

int get(int key){
    int idx=hasfunction(key);

    while (hashmap[idx].)
    {
        
    }
    
}