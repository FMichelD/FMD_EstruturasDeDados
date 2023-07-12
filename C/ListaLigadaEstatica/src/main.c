#include "List.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[]) 
{
    List *list = (List*)malloc(sizeof(List));
    
    listInit(list);
    printf("Quantidade de elementos: %d\n", listSize(list));

    Register r1;
    r1.key = 10;

    // is not possible to insert  data in the middle of an empty list
    //assert(listInsertAt(list, r1, 10) && "is not possible to insert  data in the middle of an empty list");

    //listInsertAt(list, r1, 0);

    listShow(list);
    
    free(list);

    return EXIT_SUCCESS;
}