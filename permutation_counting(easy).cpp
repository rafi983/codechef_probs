#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, 998244353 - 2);
}

const int MAXN = 200005;
long long fact[MAXN];
long long invFact[MAXN];

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % 998244353;
        invFact[i] = modInverse(fact[i]);
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % 998244353 * invFact[n - r] % 998244353;
}

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    int c1 = (N - 1) / 3 + 1;
    int c2 = (N - 2) / 3 + 1;
    int c0 = N - c1 - c2;

    int M = c1 + c2;
    long long ans = 0;

    if (c1 == 0) {
        if (c0 <= M + 1) {
            ans = nCr(M + 1, c0);
        }
    } else if (c2 == 0) {
        if (c0 <= M + 1) {
            ans = nCr(M + 1, c0);
        }
    } else {
        for (int m = 1; m <= c1; m++) {
            // Case A: m blocks of 1, m blocks of 2. k = 2m - 1
            int k = 2 * m - 1;
            if (k <= c0) {
                long long ways = nCr(c1 - 1, m - 1) * nCr(c2 - 1, m - 1) % 998244353;
                ways = ways * 2 % 998244353;
                long long place0 = nCr(M + 1 - k, c0 - k);
                ans = (ans + ways * place0) % 998244353;
            }

            // Case B: m blocks of 1, m-1 blocks of 2. k = 2m - 2
            k = 2 * m - 2;
            if (k <= c0) {
                 long long ways = nCr(c1 - 1, m - 1) * nCr(c2 - 1, m - 2) % 998244353;
                 long long place0 = nCr(M + 1 - k, c0 - k);
                 ans = (ans + ways * place0) % 998244353;
            }

            // Case C: m blocks of 1, m+1 blocks of 2. k = 2m
            k = 2 * m;
            if (k <= c0) {
                 long long ways = nCr(c1 - 1, m - 1) * nCr(c2 - 1, m) % 998244353;
                 long long place0 = nCr(M + 1 - k, c0 - k);
                 ans = (ans + ways * place0) % 998244353;
            }
        }
    }

    ans = ans * fact[c0] % 998244353;
    ans = ans * fact[c1] % 998244353;
    ans = ans * fact[c2] % 998244353;

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int T;
    if (cin >> T) {
        while(T--) {
            solve();
        }
    }
    return 0;
}

