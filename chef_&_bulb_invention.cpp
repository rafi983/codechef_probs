#include <iostream>

using namespace std;

void solve() {
    long long N, p, K;
    if (!(cin >> N >> p >> K)) return;

    long long ans = 0;
    long long r = p % K;
    long long q = N / K;
    long long rem = N % K;

    if (r <= rem) {
        ans = r * (q + 1);
    } else {
        ans = rem * (q + 1) + (r - rem) * q;
    }

    ans += (p - r) / K + 1;

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

