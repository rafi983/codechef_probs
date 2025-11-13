#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int a[2000];
        for(int i = 0; i < 2*n; i++) {
            scanf("%d", &a[i]);
        }

        qsort(a, 2*n, sizeof(int), compare);

        int valid = 1;
        int i = 0;

        while(i < 2*n && valid) {
            int count = 1;
            int current = a[i];

            while(i + count < 2*n && a[i + count] == current) {
                count++;
            }

            if(count > 2) {
                valid = 0;
            }

            i += count;
        }

        if(valid) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
