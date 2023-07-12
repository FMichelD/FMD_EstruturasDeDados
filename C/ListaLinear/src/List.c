#include "List.h"

#include <stdio.h>

void listInit(List *list)
{
    list->nroElem = 0;
}

void listShow(const List *list)
{
    printf("List: \"");

    for(int i = 0; i < list->nroElem; ++i)
    {
        printf("%i", list->data[i].key);
    }

    printf("\"\n");
}

int listSize(const List *list) 
{
    return list->nroElem;
}

int sequentialSearch(const List *list, Key key)
{
    int i = 0;
    while(i < list->nroElem)
    {
        if(key == list->data[i].key)
            return i;
        else
            ++i;
    }
    
    return -1;
}

bool listInsertAt(List *list, Register reg, int pos)
{
    if((list->nroElem == MAX) || (pos < 0) || (pos > list->nroElem) || (pos >= MAX))
        return false;
    
    for(int j = list->nroElem; j > pos; --j)
    {
        list->data[j] = list->data[j - 1];
    }
    list->data[pos] = reg;
    list->nroElem++;
    
    return true;
}

bool listExcludeKey(List *list, Key key)
{
    int pos = sequentialSearch(list, key);

    if(pos == -1)
        return false;
    
    for(int i = pos; i < list->nroElem - 1; ++i)
        list->data[i] = list->data[i + 1];
    
    list->nroElem--;
    return true;
}

void listReset(List *list)
{
    list->nroElem = 0;
}

int listSearchWithSentinel(List *list, Key key)
{
    int i = 0;
    list->data[list->nroElem].key = key;
    while(list->data[i].key != key)
        ++i;
    
    if(i == list->nroElem)
        return -1;
}

bool listInsertOrdered(List *list, Register reg)
{
    if(list->nroElem >= MAX)
        return false;

    int pos = list->nroElem;
    while (pos > 0 && list->data[pos - 1].key > reg.key)
    {
        list->data[pos] = list->data[pos - 1];
        --pos;
    }
    list->data[pos] = reg;
    list->nroElem++;
    return true;
}

int listBinarySearch(List *list, Key key)
{
    int left, right, middle;
    left = 0;
    right = list->nroElem - 1;
    while(left <= right)
    {
        middle = ((left + right) / 2);
        if(list->data[middle].key == key)
            return middle;
        else {
            if(list->data[middle].key < key)
                left = middle + 1;
            else
                right = middle - 1;
        }
    }
    return -1;
}