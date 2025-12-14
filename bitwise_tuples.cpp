#include <iostream>

using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 1000000007;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 1000000007;
        base = (base * base) % 1000000007;
        exp /= 2;
    }
    return res;
}

void solve() {
    long long N, M;
    if (!(cin >> N >> M)) return;

    long long two_pow_n = power(2, N);
    long long base = (two_pow_n - 1 + 1000000007) % 1000000007;
    long long ans = power(base, M);

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

