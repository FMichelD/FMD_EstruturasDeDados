#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MAX 50
#define INVALID -1
typedef int Key;

typedef struct {
    Key key;
    // another fields
}Register;

typedef struct element {
    Register reg;
    struct element *next;
}Element;

typedef struct {
    Element *first;
}List;


void listInit(List *list);
void listShow(const List *list);
int listSize(const List *list);
Element* listSequentialSearch(const List *list, Key key);
Element* listOrderedSearch(List *list, Key key);
bool listInsertOrdered(List *list, Register reg);
bool listDeleteByKey(List *list, Key key);
void listReset(List *list);
#endif