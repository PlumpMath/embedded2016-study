#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr)    (sizeof(arr) / sizeof((arr)[0]))

extern void BubbleSort(int A[], int cnt, bool asc);

static int array[] = { -32, -10, 23, -5, 228, 0, -16, 1, -3, 11 };

void print_list(int A[], int cnt)
{
        for (int i = 0; i < cnt; i++) {
                printf(" %d, ", A[i]);
        }
        printf("\n");
}

int main(int argc, char *argv[])
{
        int count = ARRAY_SIZE(array);

        printf("\n------ Start Bubble Sort ----- \n\n");

        printf("Original list:\n");
        print_list(array, count);
        printf("\n");

        BubbleSort(array, count, false);

        printf("Sorted list (bubble sort):\n");
        print_list(array, count);
        printf("\n");

        return 0;
}
