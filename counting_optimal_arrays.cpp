#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long N, M;
    cin >> N >> M;

    if (N == 1) {
        cout << (M + 1) % 998244353 << endl;
        return;
    }

    long long L = 0;
    long long tempM = M;
    while (tempM > 0) {
        tempM >>= 1;
        L++;
    }

    long long K = (1LL << L) - 1;
    long long ans = (2 * M - K + 1);

    ans %= 998244353;
    if (ans < 0) ans += 998244353;

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
