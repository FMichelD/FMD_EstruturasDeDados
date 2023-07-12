#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#define MAX 50
typedef int Key;

typedef struct {
    Key key;
    // another fields
}Register;

typedef struct {
    Register data[MAX + 1];
    int nroElem;
}List;

void listInit(List *list);
void listShow(const List *list);
int listSize(const List *list);
int sequentialSearch(const List *list, Key key);
bool listInsertAt(List *list, Register reg, int pos);
bool listExcludeReg(List *list, Key key);
void listReset(List *list);
int listSearchWithSentinel(List *list, Key key);
bool listInsertOrdered(List *list, Register reg);
int listBinarySearch(List *list, Key key);

#endif