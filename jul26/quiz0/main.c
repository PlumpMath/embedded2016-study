#include <stdio.h>
#include <stdint.h>

#define ARRAY_SIZE(arr)    (sizeof(arr) / sizeof((arr)[0]))

int is_aligned (const uint8_t *p, uint8_t byte_count)
{
        return ((uintptr_t) p % (size_t) byte_count == 0) ? 1 : 0;
}

int main(int argc, char *argv[])
{
        void* data[] = {
                (void *) 0,          /*  is_aligned()  */
                (void *) 0xABCD7FFF, /* !is_aligned() */
                (void *) 0xABCD8000, /*  is_aligned()  */
        };

        int pattern[] = {
                0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80
        };

        printf("\n------ Start is_aligned test ----- \n\n");

        for(int i = 0; i < ARRAY_SIZE(data); i++) {
                for (int j = 0; j < ARRAY_SIZE(pattern); j++) {
                        printf("is_aligned(0x%02x, 0x%02x) = %d \n", data[i], pattern[j], is_aligned(data[i], pattern[j]));
                }
                printf("\n");
        }
        printf("\n");

        return 0;
}
