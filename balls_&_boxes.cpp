#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MOD = 998244353;

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

// NTT implementation
void ntt(vector<long long>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        long long wlen = power(3, (MOD - 1) / len);
        if (invert) wlen = modInverse(wlen);
        for (int i = 0; i < n; i += len) {
            long long w = 1;
            for (int j = 0; j < len / 2; j++) {
                long long u = a[i + j], v = (a[i + j + len / 2] * w) % MOD;
                a[i + j] = (u + v < MOD ? u + v : u + v - MOD);
                a[i + j + len / 2] = (u - v >= 0 ? u - v : u - v + MOD);
                w = (w * wlen) % MOD;
            }
        }
    }
    if (invert) {
        long long n_inv = modInverse(n);
        for (long long& x : a)
            x = (x * n_inv) % MOD;
    }
}

vector<long long> multiply(vector<long long> const& a, vector<long long> const& b) {
    vector<long long> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] = (fa[i] * fb[i]) % MOD;
    ntt(fa, true);
    vector<long long> result = fa;
    while(result.size() > 1 && result.back() == 0) result.pop_back();
    return result;
}

const int MAX_FACT = 2000005;
long long fact[MAX_FACT];
long long invFact[MAX_FACT];

void precomputeFactorials() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX_FACT; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX_FACT - 1] = modInverse(fact[MAX_FACT - 1]);
    for (int i = MAX_FACT - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N + 1);
    long long S_N = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        S_N += A[i];
    }
    int M;
    cin >> M; // A_{N+1}

    // DP to compute coefficients of product(1 - z^{A_i})
    // dp[w]
    vector<long long> dp(S_N + 1, 0);
    dp[0] = 1;
    int current_sum = 0;
    for (int i = 1; i <= N; ++i) {
        int val = A[i];
        current_sum += val;
        for (int j = current_sum; j >= val; --j) {
            dp[j] = (dp[j] - dp[j - val]);
            if (dp[j] < 0) dp[j] += MOD;
        }
    }

    // Prepare polynomials for convolution
    // G(z) = sum (k - N - i)! z^i
    // H(z) = sum (1/j!) z^j
    // k = S_N + M - 1
    long long k = S_N + M - 1;
    int limit = S_N - N;

    vector<long long> G(limit + 1);
    for (int i = 0; i <= limit; ++i) {
        if (k - N - i >= 0)
            G[i] = fact[k - N - i];
        else
            G[i] = 0;
    }

    vector<long long> H(limit + 1);
    for (int j = 0; j <= limit; ++j) {
        H[j] = invFact[j];
    }

    vector<long long> F = multiply(G, H);

    // Compute Answer
    // Ans = K * (-1)^N * sum(dp[w] * w! * f(w))
    // f(w) = coeff of z^{w-N} in F

    long long sum_val = 0;
    for (int w = N; w <= S_N; ++w) {
        if (dp[w] == 0) continue;
        int idx = w - N;
        if (idx < F.size()) {
            long long term = (dp[w] * fact[w]) % MOD;
            term = (term * F[idx]) % MOD;
            sum_val = (sum_val + term) % MOD;
        }
    }

    long long K_val = invFact[M - 1];
    for (int i = 1; i <= N; ++i) {
        K_val = (K_val * invFact[A[i]]) % MOD;
    }

    long long ans = (sum_val * K_val) % MOD;
    if (N % 2 == 1) {
        ans = (MOD - ans) % MOD;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomputeFactorials();
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
