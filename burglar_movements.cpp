#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n + 2, 0);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<vector<int>> dpL1(n + 2, vector<int>(k + 1, 0));
        vector<vector<int>> dpL2(n + 2, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dpL1[i][j] = dpL1[i - 1][j - 1];
                if (j >= 2) dpL2[i][j] = dpL2[i - 1][j - 2];

                if (j >= 2) dpL1[i][j] = max(dpL1[i][j], a[i] + dpL1[i - 1][j - 2]);
                else dpL1[i][j] = max(dpL1[i][j], a[i]);

                if (j >= 3) dpL2[i][j] = max(dpL2[i][j], a[i] + dpL2[i - 1][j - 3]);
                else dpL2[i][j] = max(dpL2[i][j], a[i]);

                dpL1[i][j] = max(dpL1[i][j], dpL1[i][j - 1]);
                dpL2[i][j] = max(dpL2[i][j], dpL2[i][j - 1]);
            }
        }

        vector<int> ans(n + 1, 0);
        vector<int> r1_next(k + 1, 0), r2_next(k + 1, 0), r1_cur(k + 1, 0), r2_cur(k + 1, 0);

        for (int s = n; s >= 1; --s) {
            r1_cur[0] = 0;
            r2_cur[0] = 0;
            for (int j = 1; j <= k; ++j) {
                r1_cur[j] = r1_next[j - 1];
                if (j >= 2) r2_cur[j] = r2_next[j - 2];
                else r2_cur[j] = 0;

                if (j >= 2) r1_cur[j] = max(r1_cur[j], a[s] + r1_next[j - 2]);
                else r1_cur[j] = max(r1_cur[j], a[s]);

                if (j >= 3) r2_cur[j] = max(r2_cur[j], a[s] + r2_next[j - 3]);
                else r2_cur[j] = max(r2_cur[j], a[s]);

                r1_cur[j] = max(r1_cur[j], r1_cur[j - 1]);
                r2_cur[j] = max(r2_cur[j], r2_cur[j - 1]);
            }

            int best = 0;
            for (int x = 0; x <= k; ++x) {
                int rem = max(0, k - x - 1);
                best = max(best, dpL2[s][x] + r1_next[rem]);
                best = max(best, r2_cur[x] + dpL1[s - 1][rem]);
            }
            ans[s] = best;

            r1_next.swap(r1_cur);
            r2_next.swap(r2_cur);
        }

        for (int s = 1; s <= n; ++s) cout << ans[s] << (s == n ? '\n' : ' ');
    }

    return 0;
}
