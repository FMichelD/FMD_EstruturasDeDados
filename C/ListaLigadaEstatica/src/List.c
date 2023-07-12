#include "List.h"

#include <stdio.h>

static void returnNode(List *list, int j);

void listInit(List *list)
{
    for(int i = 0; i < MAX - 1; ++i)
        list->data[i].next = i + 1;
    
    list->data[MAX - 1].next = INVALID;
    list->first = INVALID;
    list->available = 0;
}

void listShow(const List *list)
{
    int i = list->first;

    printf("List: \"");

    while (i != INVALID)
    {
        printf("%i ", list->data[i].reg.key);
        i = list->data[i].next;
    }

    printf("\"\n");
}

int listSize(const List *list) 
{
    int i = list->first;
    int size = 0;
    while(i != INVALID)
    {
        size++;
        i = list->data[i].next;
    }
    return size;
}

int listOrderedSearch(const List *list, Key key)
{
    int i = list->first;
    while (i != INVALID && list->data[i].reg.key < key )
        i = list->data[i].next;

    if(i != INVALID && list->data[i].reg.key == key)
        return i;
    else
        return INVALID;
}

bool listExcludeByKey(List *list, Key key)
{
    int previous = INVALID;
    int i = list->first;
    while((i != INVALID) && (list->data[i].reg.key < key))
    {
        previous = i;
        i = list->data[i].next;
    }

    if(i == INVALID || list->data[i].reg.key != key)
        return false;
    
    if(previous == INVALID)
        list->first = list->data[i].next;
    else
        list->data[previous].next = list->data[i].next;

    returnNode(list, i);
    return true;
}

static void returnNode(List *list, int j)
{
    list->data[j].next = list->available;
    list->available = j;
}

void listReset(List *list)
{
    listInit(list);
}

bool listInsertOrdered(List *list, Register reg)
{
    if(list->available == INVALID)
        return false;
    
    int previous = INVALID;
    int i = list->first;
    Key key = reg.key;

    while((i != INVALID) && (list->data[i].reg.key < key))
    {
        previous = i;
        i = list->data[i].next;
    }

    if(i != INVALID && list->data[i].reg.key == key)
        return false;
    
    i = listGetNode(list);
    list->data[i].reg = reg;

    if(previous == INVALID)
    {
        list->data[i].next = list->first;
        list->first = i;
    } else {
        list->data[i].next = list->data[previous].next;
        list->data[previous].next = i;
    }
    return true;
}

int listGetNode(List *list)
{
    int result = list->available;
    if(list->available != INVALID)
        list->available = list->data[list->available].next;

    return result;
}