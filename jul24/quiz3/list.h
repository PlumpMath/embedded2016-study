#ifndef _LIST_H_
#define _LIST_H_

typedef struct list {
        int data;
        struct list *next;
} LIST;

void print_list( LIST *t );
LIST *append( LIST *start, int newdata );
LIST *list_switch( LIST *l1, LIST *l2 );

#endif /* _LIST_H_ */