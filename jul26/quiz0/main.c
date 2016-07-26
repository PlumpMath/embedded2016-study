#include <stdio.h>
#include <stdint.h>

#define ARRAY_SIZE(arr)    (sizeof(arr) / sizeof((arr)[0]))

int is_aligned (const uint8_t *p, uint8_t byte_count)
{
        return ((uintptr_t) p % (size_t) byte_count == 0) ? 1 : 0;
}

int main(int argc, char *argv[])
{
        /* contents: (address, byte_count) */
        int arr[] = {
                /* is_aligned */
                0x00,0x01, 0x00,0x02, 0x00,0x04, 0x00,0x08,
                0x00,0x10, 0x00,0x20, 0x00,0x40, 0x00,0x80,

                /* ! is_aligned */
                0x01,0x02, 0x03,0x04, 0x07,0x08, 0x0F,0x10,
                0x1F,0x20, 0x3F,0x40, 0x7F,0x80, 0x02,0x02,

                /* is_aligned */
                0x04,0x04, 0x08,0x08, 0x10,0x10, 0x20,0x20,
                0x40,0x40, 0x80,0x80,
        };

        printf("\n------ Start is_aligned test ----- \n\n");

        for(int i = 0; i < ARRAY_SIZE(arr); i += 2) {
                printf("is_aligned(0x%x, 0x%x) = %d \n", arr[i], arr[i + 1], is_aligned(arr[i], arr[i + 1]));
        }
        printf("\n");

        return 0;
}
