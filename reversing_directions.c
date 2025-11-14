#include <stdio.h>
#include <string.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }
    getchar();
    while (t--) {
        int n;
        scanf("%d", &n);
        getchar();
        char dirs[40][10];
        char roads[40][64];
        char line[128];
        for (int i = 0; i < n; i++) {
            if (!fgets(line, sizeof(line), stdin)) {
                return 0;
            }
            size_t len = strlen(line);
            if (len && line[len - 1] == '\n') {
                line[len - 1] = '\0';
            }
            char *on = strstr(line, " on ");
            if (!on) {
                return 0;
            }
            strcpy(roads[i], on + 4);
            *on = '\0';
            strcpy(dirs[i], line);
        }
        printf("Begin on %s\n", roads[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            if (strcmp(dirs[i + 1], "Left") == 0) {
                printf("Right on %s\n", roads[i]);
            } else {
                printf("Left on %s\n", roads[i]);
            }
        }
        if (t) {
            printf("\n");
        }
    }
    return 0;
}

