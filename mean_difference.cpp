#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> a(N);
        for (int i = 0; i < N; ++i) cin >> a[i];
        sort(a.begin(), a.end());

        long long ans = 0;
        long long m = a.front();
        long long M = a.back();

        if (N >= 2) {
            vector<long long> desc;
            desc.reserve(N - 1);
            for (int i = N - 1; i >= 1; --i) desc.push_back(a[i]);
            long long ps = 0;
            for (int k = 1; k <= (int)desc.size(); ++k) {
                ps += desc[k - 1];
                long long avg_floor = (m + ps) / (k + 1);
                ans = max(ans, avg_floor - m);
            }

            long long qs = 0;
            for (int k = 1; k <= N - 1; ++k) {
                qs += a[k - 1];
                long long avg_floor = (M + qs) / (k + 1);
                ans = max(ans, M - avg_floor);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}

