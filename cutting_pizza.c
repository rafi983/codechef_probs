#include <stdio.h>

static void get_divisors(int divisors[], int *count) {
    *count = 0;
    for (int d = 1; d <= 360; d++) {
        if (360 % d == 0) {
            divisors[(*count)++] = d;
        }
    }
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    int divisors[360];
    int div_count;
    get_divisors(divisors, &div_count);
    while (T--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        int angles[360];
        for (int i = 0; i < n; i++) {
            scanf("%d", &angles[i]);
        }
        for (int i = 1; i < n; i++) {
            int key = angles[i];
            int j = i - 1;
            while (j >= 0 && angles[j] > key) {
                angles[j + 1] = angles[j];
                j--;
            }
            angles[j + 1] = key;
        }
        int unique = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || angles[i] != angles[i - 1]) {
                angles[unique++] = angles[i];
            }
        }
        if (unique == 0) {
            printf("0\n");
            continue;
        }
        int gaps[361];
        int gap_count = 0;
        for (int i = 1; i < unique; i++) {
            gaps[gap_count++] = angles[i] - angles[i - 1];
        }
        gaps[gap_count++] = 360 - angles[unique - 1] + angles[0];
        int best = 360;
        for (int idx = 0; idx < div_count; idx++) {
            int slices = divisors[idx];
            int slice_angle = 360 / slices;
            int additions = 0;
            int possible = 1;
            for (int g = 0; g < gap_count; g++) {
                if (gaps[g] % slice_angle != 0) {
                    possible = 0;
                    break;
                }
                additions += gaps[g] / slice_angle - 1;
                if (additions >= best) {
                    possible = 0;
                    break;
                }
            }
            if (possible && additions < best) {
                best = additions;
            }
        }
        printf("%d\n", best);
    }
    return 0;
}

