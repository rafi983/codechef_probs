#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N;
        if (scanf("%d", &N) != 1) return 0;
        int *arr = (int *)malloc(N * sizeof(int));
        int *dep = (int *)malloc(N * sizeof(int));
        if (!arr || !dep) return 0;
        for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);
        for (int i = 0; i < N; ++i) scanf("%d", &dep[i]);
        qsort(arr, N, sizeof(int), cmp_int);
        qsort(dep, N, sizeof(int), cmp_int);
        int i = 0, j = 0, cur = 0, best = 0;
        while (i < N && j < N) {
            if (arr[i] < dep[j]) {
                cur++;
                if (cur > best) best = cur;
                i++;
            } else {
                cur--;
                j++;
            }
        }
        printf("%d\n", best);
        free(arr);
        free(dep);
    }
    return 0;
}

