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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<vector<char>> good(n + 2, vector<char>(n + 2, 0));

        for (int l = 1; l <= n; ++l) {
            vector<int> freq(n + 1, 0);
            int singles = 0;

            for (int r = l; r <= n; ++r) {
                int x = a[r];
                if (freq[x] == 0) ++singles;
                else if (freq[x] == 1) --singles;
                ++freq[x];

                good[l][r] = (singles > 0);
            }
        }

        vector<vector<char>> beautiful(n + 2, vector<char>(n + 2, 0));
        for (int i = 1; i <= n; ++i) beautiful[i][i] = 1;

        for (int len = 2; len <= n; ++len) {
            for (int l = 1; l + len - 1 <= n; ++l) {
                int r = l + len - 1;
                beautiful[l][r] = (good[l][r] && beautiful[l + 1][r] && beautiful[l][r - 1]);
            }
        }

        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];

            for (int l = 1; l <= i; ++l) {
                if (!beautiful[l][i]) continue;
                int keep = i - l + 1;
                int prev = (l >= 2 ? dp[l - 2] : 0);
                dp[i] = max(dp[i], prev + keep);
            }
        }

        cout << (n - dp[n]) << '\n';
    }

    return 0;
}
