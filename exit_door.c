#include <stdio.h>

#define MAXN 400000

static int BIT[MAXN + 5];
static int positions[MAXN + 5];

static inline void bit_add(int n, int idx, int val) {
    for (; idx <= n; idx += idx & -idx) BIT[idx] += val;
}

static inline int bit_sum(int idx) {
    int s = 0;
    for (; idx > 0; idx -= idx & -idx) s += BIT[idx];
    return s;
}

int main(void) {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        int N;
        if (scanf("%d", &N) != 1) return 0;
        if (N > MAXN) return 0;
        for (int i = 1; i <= N; ++i) {
            int x;
            scanf("%d", &x);
            positions[x] = i;
        }
        for (int i = 1; i <= N; ++i) BIT[i] = 0;
        long long total = 0;
        for (int v = 1; v <= N; ++v) {
            int pos = positions[v];
            int left_smaller = bit_sum(pos - 1);
            int inserted = v - 1;
            int right_smaller = inserted - left_smaller;
            total += (left_smaller < right_smaller) ? left_smaller : right_smaller;
            bit_add(N, pos, 1);
        }
        printf("%lld\n", total);
    }
    return 0;
}

