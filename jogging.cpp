#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long n, x;
        cin >> n >> x;

        if (n == 1) {
            cout << x % MOD << "\n";
        } else {
            long long ans = x * power(2, n - 1, MOD) % MOD;
            cout << ans << "\n";
        }
    }

    return 0;
}

