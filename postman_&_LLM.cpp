#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long MOD = 998244353;
const int MAXN = 200005;
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

long long nCr_mod(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    vector<long long> d(N);
    map<long long, int> total_counts;
    for (int i = 0; i < N; ++i) {
        cin >> d[i];
        total_counts[d[i]]++;
    }
    sort(d.begin(), d.end());

    long long current_S = 0;
    long long current_W = 0;

    for (int k = 1; k <= M; ++k) {
        long long coeff = 2LL * (2LL * k - 1 - M);
        current_S += coeff * d[k-1];
        current_W += d[k-1];
    }

    long long min_S = current_S;

    map<long long, int> window_counts;
    for (int i = 0; i < M; ++i) {
        window_counts[d[i]]++;
    }

    long long current_ways = 1;
    for (auto const& [val, count] : window_counts) {
        int total = total_counts[val];
        current_ways = (current_ways * nCr_mod(total, count)) % MOD;
    }

    long long total_valid_ways = current_ways;

    for (int i = 1; i <= N - M; ++i) {
        long long term1 = (2LL * M - 2) * d[i + M - 1];
        long long term2 = (2LL * M + 2) * d[i - 1];
        long long term3 = 4LL * current_W;

        long long next_S = current_S + term1 + term2 - term3;
        long long next_W = current_W - d[i - 1] + d[i + M - 1];

        long long u = d[i - 1];
        long long v = d[i + M - 1];

        if (u != v) {
            int C_u = total_counts[u];
            int c_u = window_counts[u];
            long long num = c_u;
            long long den = C_u - c_u + 1;
            current_ways = current_ways * num % MOD * modInverse(den) % MOD;
            window_counts[u]--;

            int C_v = total_counts[v];
            int c_v = window_counts[v];
            num = C_v - c_v;
            den = c_v + 1;
            current_ways = current_ways * num % MOD * modInverse(den) % MOD;
            window_counts[v]++;
        }

        current_S = next_S;
        current_W = next_W;

        if (current_S < min_S) {
            min_S = current_S;
            total_valid_ways = current_ways;
        } else if (current_S == min_S) {
            if (u != v) {
                total_valid_ways = (total_valid_ways + current_ways) % MOD;
            }
        }
    }

    cout << min_S << " " << total_valid_ways << "\n";
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

