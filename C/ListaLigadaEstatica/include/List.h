#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#define MAX 50
#define INVALID -1
typedef int Key;

typedef struct {
    Key key;
    // another fields
}Register;

typedef struct {
    Register reg;
    int next;
}Element;

typedef struct {
    Element data[MAX];
    int first;
    int available;
}List;


void listInit(List *list);
void listShow(const List *list);
int listSize(const List *list);
int listOrderedSearch(const List *list, Key key);
bool listExcludeByKey(List *list, Key key);
void listReset(List *list);
bool listInsertOrdered(List *list, Register reg);
int listGetNode(List *list);

#endif