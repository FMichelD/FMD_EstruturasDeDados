#include "List.h"

#include <stdio.h>

static Element* listSequentialSearchExc(List *list, Key key, Element  **previous);

void listInit(List *list)
{
    list->first = NULL;
}

void listShow(const List *list)
{
    Element *end = list->first;

    printf("List: \"");

    while (end != NULL)
    {
        printf("%i ", end->reg.key);
        end = end->next;
    }
    printf("\"\n");
}

int listSize(const List *list) 
{
    Element *end = list->first;
    int size = 0;

    while(end != NULL)
    {
        size++;
        end = end->next;
    }
    return size;
}

Element* listSequentialSearch(const List *list, Key key)
{
    Element *pos = list->first;
    while (pos != NULL) 
    {
        if(pos->reg.key == key)
            return pos;
    }
    return NULL;
}

Element* listOrderedSearch(List *list, Key key)
{
    Element *pos = list->first;
    while (pos != NULL && pos->reg.key < key)
    {
        pos = pos->next;
    }
    
    if(pos != NULL && pos->reg.key == key)
        return pos;
    
    return NULL;
}

static Element* listSequentialSearchExc(List *list, Key key, Element  **previous)
{
    *previous = NULL;
    Element *actual = list->first;
    while((actual != NULL) && (actual->reg.key < key))
    {
        *previous = actual;
        actual = actual->next;
    }

    if((actual != NULL) && (actual->reg.key == key))
        return actual;
    
    return NULL;
}

bool listInsertOrdered(List *list, Register reg)
{
    Key key = reg.key;
    Element *previous;
    Element *i;

    i = listSequentialSearchExc(list, key, &previous);
    
    if(i != NULL)
        return NULL;

    i = (Element*)malloc(sizeof(Element));
    i->reg = reg;

    if(previous == NULL)
    {
        i->next = list->first;
        list->first = i;
    } else {
        i->next = previous->next;
        previous->next = i;
    }

    return true;
}

bool listDeleteByKey(List *list, Key key)
{
    Element *previous;
    Element *i;

    i = listSequentialSearchExc(list, key, &previous);

    if(i == NULL)
        return false;

    if(previous == NULL )
        list->first = i->next;
    else
        previous->next = i->next;
    
    free(i);

    return true;
}

void listReset(List *list)
{
    Element *end = list->first;

    while(end != NULL)
    {
        Element *erase = end;
        end = end->next;
        free(erase);
    }
    list->first = NULL;
}