#include <stdio.h>

#define swap(t, x, y) do {                \
                          t tmp_ = (x);   \
                          (x) = (y);      \
                          (y) = tmp_;     \
                      } while (0)

int main()
{
    int x = 2, y = 3;

    printf("Before swap: x = %d, y = %d\n", x, y);

    swap(int, x, y);
    printf("After swap:  x = %d, y = %d\n", x, y);

    return 0;
}
