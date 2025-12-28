#include <iostream>
#include <vector>

using namespace std;

long long MOD = 998244353;
const int MAXN = 10005;

long long fact[MAXN];
long long invFact[MAXN];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

long long nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[n - r] % MOD;
}

void solve() {
    int N;
    long long K_long;
    if (!(cin >> N >> K_long)) return;

    if (2 * K_long > N) {
        cout << power(K_long, N) << "\n";
        return;
    }

    int K = (int)K_long;
    long long C = 0;

    // C = sum_{j=1}^K (-1)^(K-j) * nCr(K, j) * sum_{q=0}^{K-j} nCr(K-j, q) * j^(N-q) * nPr(N, q)

    for (int j = 1; j <= K; ++j) {
        long long inner_sum = 0;
        int limit = K - j;

        long long j_pow = power(j, N - limit);

        for (int q = limit; q >= 0; --q) {
            long long term = nCr(limit, q);
            term = (term * j_pow) % MOD;
            term = (term * nPr(N, q)) % MOD;
            inner_sum = (inner_sum + term) % MOD;

            if (q > 0) j_pow = (j_pow * j) % MOD;
        }

        long long term_j = nCr(K, j);
        term_j = (term_j * inner_sum) % MOD;

        if ((K - j) % 2 == 1) {
            C = (C - term_j + MOD) % MOD;
        } else {
            C = (C + term_j) % MOD;
        }
    }

    long long total = power(K, N);
    long long ans = (total - C + MOD) % MOD;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}

