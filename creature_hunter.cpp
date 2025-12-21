#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int N;
    long long H;
    if (!(cin >> N >> H)) return;

    long long d1 = 0;
    long long d2 = 0;

    for (int i = 0; i < N; ++i) {
        int s;
        long long d;
        cin >> s >> d;
        if (s == 1) {
            d1 = max(d1, d);
        } else {
            d2 = max(d2, d);
        }
    }

    if (d1 == 0) {
        // Only type 2 available
        long long hits = (H + d2 - 1) / d2;
        cout << hits * 2 << "\n";
        return;
    }

    if (d2 == 0) {
        // Only type 1 available
        long long hits = (H + d1 - 1) / d1;
        cout << hits << "\n";
        return;
    }

    // Both available
    if (2 * d1 >= d2) {
        // Type 1 is more efficient or equal per time unit
        long long hits = (H + d1 - 1) / d1;
        cout << hits << "\n";
    } else {
        // Type 2 is more efficient
        // Option 1: Only use d2
        long long time1 = ((H + d2 - 1) / d2) * 2;

        // Option 2: Use d1 once, then d2
        long long remH = max(0LL, H - d1);
        long long hits2 = (remH + d2 - 1) / d2;
        long long time2 = 1 + hits2 * 2;

        cout << min(time1, time2) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

