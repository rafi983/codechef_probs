#include <iostream>
#include <vector>
#include <algorithm>

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

// Precomputed factorials
vector<long long> fact;
vector<long long> invFact;

void precomputeFactorials(int n) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % 998244353;
    invFact[n] = modInverse(fact[n]);
    for (int i = n - 1; i >= 0; i--) invFact[i] = (invFact[i + 1] * (i + 1)) % 998244353;
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % 998244353 * invFact[n - r] % 998244353;
}

// Global caching for W values to reuse memory
vector<vector<long long>> memo_W;
vector<bool> memo_used;

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    vector<int> cnt(N + 1, 0);
    int max_val = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] < N + 1) cnt[A[i]]++;
        if (A[i] > max_val) max_val = A[i];
    }

    // To minimize memory/time, only init memo for existing counts
    vector<int> distinct_counts;
    for (int i = 0; i <= N; ++i) { // scan up to N because count can be at i
        if (cnt[i] > 0) {
            if (!memo_used[cnt[i]]) {
                distinct_counts.push_back(cnt[i]);
                memo_used[cnt[i]] = true;
            }
        }
    }

    // Precompute W for distinct counts
    for (int count : distinct_counts) {
        if (memo_W[count].size() <= count) memo_W[count].resize(count + 2);

        // W(n, n+1) = 0
        memo_W[count][count + 1] = 0;
        long long current_W = 0;
        for (int c = count; c >= 1; --c) {
            long long comb = nCr(count, c);
            current_W = (current_W + comb) % 998244353;
            memo_W[count][c] = current_W;
        }
    }

    vector<int> suf_cnt(N + 2, 0);
    for (int i = N; i >= 0; --i) {
        suf_cnt[i] = suf_cnt[i + 1] + cnt[i];
    }

    // Powers of 2
    vector<long long> pow2(N + 1);
    pow2[0] = 1;
    for (int i = 1; i <= N; ++i) pow2[i] = (pow2[i - 1] * 2) % 998244353;

    long long ans = 0;

    // Iterate c
    // c goes up to N.
    for (int c = 1; c <= N; ++c) {
        long long current_P = 1;

        // Iterate k
        for (int k = 0; ; ++k) {
            // Calculate Q_k(c) = 2 ^ suf_cnt[k+c]
            long long Q = 1;
            int idx = k + c;
            if (idx <= N + 1) { // suf_cnt valid indices up to N+1
                 Q = pow2[suf_cnt[idx]];
            }
            long long term = 0;
            if (k == 0) {
                term = current_P * (Q - 1 + 998244353) % 998244353;
            } else if (k == 1) {
                term = current_P * (Q - 1 + 998244353) % 998244353;
            } else {
                term = current_P * Q % 998244353;
            }

            ans = (ans + term) % 998244353;

             if (k >= N + 1) { // Safety break if k exceeds bounds
                break;
            }

            long long factor = 0;
            if (k == 0) {
                factor = (pow2[cnt[0]] - 1 + 998244353) % 998244353;
            } else {
                int count = cnt[k];
                if (count < c) factor = 0;
                else factor = memo_W[count][c];
            }

            if (factor == 0) break; // Chain breaks

            current_P = (current_P * factor) % 998244353;
        }
    }

    cout << ans << "\n";

    // Cleanup memo_used for next test case
    for (int count : distinct_counts) {
        memo_used[count] = false;

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precomputeFactorials(1000005);
    memo_W.resize(1000005);
    memo_used.resize(1000005, false);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
