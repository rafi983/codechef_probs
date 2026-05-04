#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n + 1), pos(n + 1, 0), free_pos(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i] == 0) {
                free_pos[i] = 1;
            } else {
                pos[a[i]] = i;
            }
        }

        vector<int> pref_free(n + 1, 0);
        for (int i = 1; i <= n; ++i) pref_free[i] = pref_free[i - 1] + free_pos[i];

        auto add_mod = [&](int &x, int y) {
            x += y;
            if (x >= MOD) x -= MOD;
        };

        auto mul_mod = [&](long long x, long long y) {
            return (int)((x * y) % MOD);
        };

        auto valid = [&](int l, int r, int v) {
            int smaller_inside = (r - l + 1) - (n - v + 1);
            return smaller_inside <= k - 3;
        };

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        if (pos[n] != 0) {
            dp[pos[n]][pos[n]] = 1;
        } else {
            for (int i = 1; i <= n; ++i) {
                if (free_pos[i]) dp[i][i] = 1;
            }
        }

        int done_free = (pos[n] == 0 ? 1 : 0);

        for (int v = n - 1; v >= 1; --v) {
            vector<vector<int>> ndp(n + 2, vector<int>(n + 2, 0));

            if (pos[v] != 0) {
                int p = pos[v];
                for (int l = 1; l <= n; ++l) {
                    for (int r = l; r <= n; ++r) {
                        int ways = dp[l][r];
                        if (ways == 0) continue;

                        int nl = min(l, p);
                        int nr = max(r, p);
                        if (!valid(nl, nr, v)) continue;
                        add_mod(ndp[nl][nr], ways);
                    }
                }
                dp.swap(ndp);
                continue;
            }

            for (int l = 1; l <= n; ++l) {
                for (int r = l; r <= n; ++r) {
                    int ways = dp[l][r];
                    if (ways == 0) continue;

                    int choices_inside = pref_free[r] - pref_free[l - 1] - done_free;
                    if (choices_inside > 0) {
                        add_mod(ndp[l][r], mul_mod(ways, choices_inside));
                    }
                }
            }

            for (int r = 1; r <= n; ++r) {
                int sum = 0;
                for (int i = r - 1; i >= 1; --i) {
                    add_mod(sum, dp[i + 1][r]);
                    if (!free_pos[i]) continue;
                    if (!valid(i, r, v)) continue;
                    add_mod(ndp[i][r], sum);
                }
            }

            for (int l = 1; l <= n; ++l) {
                int sum = 0;
                for (int i = l + 1; i <= n; ++i) {
                    add_mod(sum, dp[l][i - 1]);
                    if (!free_pos[i]) continue;
                    if (!valid(l, i, v)) continue;
                    add_mod(ndp[l][i], sum);
                }
            }

            dp.swap(ndp);
            ++done_free;
        }

        cout << dp[1][n] << '\n';
    }

    return 0;
}
