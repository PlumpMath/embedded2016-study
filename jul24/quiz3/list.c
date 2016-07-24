#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void print_list( LIST *t )
{
        while( t != NULL ) {
                printf( "%d\n", t->data );
                t = t->next;
        }
}

LIST *append( LIST *start, int newdata )
{
        LIST *new, *end, *ret;

        if( (new = (LIST *)malloc(sizeof(LIST))) == NULL) {
                fprintf( stderr, "Memory Allocation error.\n" );
                // In Windows, replace following with a return statement.
                exit(1);
        }
        if( start == NULL )
                ret = new;
        else {
                ret = start;
                end = start;
                while( end->next != NULL ) end = end->next;
                end->next = new;
        }
        new->data = newdata;
        new->next = NULL;
        return ret ;
}

LIST *list_switch( LIST *l1, LIST *l2 )
{
        l1->next = l2->next;
        l2->next = l1;
        return l2;
}
