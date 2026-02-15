#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    ll A, B, K;
    if (!(cin >> A >> B >> K)) return;

    if (K == 1) {
        cout << 0 << "\n";
        return;
    }


    ll low = 0, high = 2000000000000000000LL;
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        ll count = 0;

        // Count 0
        if (mid >= 0) count++;


        if (mid >= B) {
            count += mid / B;
        }

        if (mid >= A) {
            count += (mid - A) / B + 1;
        }

        if (count >= K) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
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

