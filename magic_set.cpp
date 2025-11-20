#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            if (a % m == 0) ++k;
        }
        unsigned long long ans = (k == 0) ? 0ULL : ((1ULL << k) - 1ULL);
        cout << ans << "\n";
    }
    return 0;
}

