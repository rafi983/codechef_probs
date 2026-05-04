#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> present(n + 3, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            present[a[i]] = 1;
        }

        int distinct_values = 0;
        for (int v = 1; v <= n; ++v) distinct_values += present[v];

        vector<int> q(n + 3, 0);
        for (int v = 1; v + 2 <= n; ++v) {
            q[v] = (present[v] && present[v + 2]) ? 1 : 0;
        }

        vector<int> suffix_best(n + 5, 0);
        for (int r = n; r >= 1; --r) {
            int pair_gain = 0;
            if (r >= 2) pair_gain = q[r] + q[r - 1];
            suffix_best[r] = max(suffix_best[r + 1], pair_gain);
        }

        for (int L = 1; L <= n; ++L) {
            int best_gain = q[L];
            if (L + 1 <= n) best_gain = max(best_gain, suffix_best[L + 1]);

            int answer = distinct_values - best_gain;
            cout << answer << (L == n ? '\n' : ' ');
        }
    }

    return 0;
}
