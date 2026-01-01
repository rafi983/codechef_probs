#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long P_MOD;
long long fact[605];
long long invFact[605];
long long powN[605];
long long W[605][605];

long long power(long long base, long long exp) {
    long long res = 1;
    base %= P_MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % P_MOD;
        base = (base * base) % P_MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, P_MOD - 2);
}

void precompute(int n) {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % P_MOD;
        invFact[i] = modInverse(fact[i]);
    }

    powN[0] = 1;
    for (int i = 1; i <= n; i++) {
        powN[i] = (powN[i - 1] * n) % P_MOD;
    }
}

long long perm(int n, int k) {
    if (k < 0) return 0;
    if (k == 0) return 1;
    if (k > n) return 0;
    return fact[n] * invFact[n - k] % P_MOD;
}

void zaman_solve() {
    int N;
    if (!(cin >> N >> P_MOD)) return;

    precompute(N);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            W[i][j] = 0;
        }
    }

    W[0][1] = 1;
    long long ans = 0;

    for (int l = 0; l < N; l++) {
        for (int p = l + 1; p <= N; p++) {
            if (W[l][p] == 0) continue;

            if (p < N) {
                long long term = W[l][p] * powN[N - l] % P_MOD;
                ans = (ans + term) % P_MOD;
            }

            for (int r = p + 1; r <= N; r++) {
                long long ways = 0;
                if (r < N) {
                    long long term1 = perm(r - l - 1, p - l);
                    long long term2 = perm(r - l - 2, p - l);
                    ways = (term1 - term2 + P_MOD) % P_MOD;
                } else {
                    long long total = powN[p - l];
                    long long waysLess = perm(N - l - 2, p - l);
                    ways = (total - waysLess + P_MOD) % P_MOD;
                }

                if (ways > 0) {
                    W[p][r] = (W[p][r] + W[l][p] * ways) % P_MOD;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while(T--) {
            zaman_solve();
        }
    }
    return 0;
}
