#include <stdio.h>
#include <stdlib.h>
#include "list.h"

LIST *list_bisect(LIST *head)
{
    LIST *fast = head, *slow = head, *prev = NULL;

    while ( fast != NULL && fast->next != NULL ) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    if ( prev != NULL) {
        prev->next = NULL;
    }
    return slow;
}

LIST *merge_list( LIST *list1, LIST *list2 )
{
    LIST dummy_head = {0, NULL}, *tail = &dummy_head;

    while ( (list1 != NULL) && (list2 != NULL) ) {
        LIST **min = (list1->data < list2->data) ? &list1 : &list2;
        LIST *next = (*min)->next;
        tail = tail->next = *min;
        *min = next;
    }
    tail->next = list1 ? list1 : list2;
    return dummy_head.next;
}

/**
 * Merge sort
 *
 *
 * @return LIST
 */
LIST *merge_sort( LIST *head )
{
    LIST *list1 = head;

    if( (list1 == NULL) || (list1->next == NULL) ) {
        return list1;
    }

    LIST *list2 = list_bisect(list1);

    return merge_list(merge_sort(list1), merge_sort(list2));
}

int main(int argc, char *argv[])
{
    LIST *try;

    // This is just testing code
    try = NULL;
    try = append( try, 5 );
    try = append( try, 2 );
    try = append( try, 9 );
    try = append( try, 8 );
    try = append( try, 1 );
    try = append( try, 7 );

    printf("\n------ Start Merge Sort ----- \n\n");

    printf("Original list:\n");
    print_list( try );
    printf("\n");

    try = merge_sort( try );
    printf("Sorted list (merge sort):\n");
    print_list( try );
    printf("\n");
}
