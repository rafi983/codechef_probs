#include <stdio.h>

int main(void) {
    int X, Y;
    if (scanf("%d %d", &X, &Y) != 2) {
        return 0;
    }
    int total = 3 * X + 2 * Y;
    printf("%d\n", total);
    return 0;
}

