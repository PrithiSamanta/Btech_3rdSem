#include <stdio.h>
#include <stdbool.h>

#define size 10
int hashset[size];

void init()
{
    for (int i = 0; i < size; i++)
    {
        hashset[i] = -1;
    }
}

int hashfunction(int key)
{
    return key % size;
}

bool add(int key)
{
    int idx = hashfunction(key);
    if (hashset[idx] == -1)
    {
        hashset[idx] == key;
        return true;
    }
    else if (hashset[idx] == key)
    {
        printf("Principle value cannot be same.\n");
        return false;
    }
    else
    {
        idx = (idx + 1) % size;
        for (int prob = 2; prob < size; prob++)
        {
            if (hashset[idx] == -1)
            {
                hashset[idx] = key;
                return true;
            }
            else if (hashset[idx] == key)
            {
                printf("Duplicate value cannot insert.\n");
                return false;
            }
            else
            {
                idx = (idx + 1) % size;
            }
        }
    }
    return false;
}

bool find(int key)
{
    int idx = hashfunction(key);

    for (int i = 0; i < size; i++)
    {
        int pos = (idx + 1) % size;

        if (hashset[pos] == -1)
        {
            return false;
        }
        if (hashset[pos] == key)
        {
            return true;
        }
    }
    return false;
}