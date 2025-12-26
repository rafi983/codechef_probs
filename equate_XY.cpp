#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    ll X, Y, Z, C;
    if (!(cin >> X >> Y >> Z >> C)) return;

    if (X == Y) {
        cout << 0 << endl;
        return;
    }

    ll ans = 2 * C;

    auto check = [&](ll A, ll B) { // A divides B
        ll D = B / A;
        // We need k | D such that |k*A - Z| is minimized
        // Iterate divisors of D
        for (ll i = 1; i * i <= D; ++i) {
            if (D % i == 0) {
                ll k1 = i;
                ll k2 = D / i;

                ll Z1 = k1 * A;
                ll cost1 = abs(Z1 - Z) + C;
                ans = min(ans, cost1);

                if (k1 != k2) {
                    ll Z2 = k2 * A;
                    ll cost2 = abs(Z2 - Z) + C;
                    ans = min(ans, cost2);
                }
            }
        }
    };

    if (Y % X == 0) {
        check(X, Y);
    }

    if (X % Y == 0) {
        check(Y, X);
    }

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

