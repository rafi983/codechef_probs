#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

vector<long long> fact, invFact;

void precomputeFactorials(int n) {
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[n] = modInverse(fact[n]);
    for (int i = n - 1; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    vector<int> c(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] <= N) c[A[i]]++;
    }

    bool possible = true;
    for (int i = 0; i < N; ++i) {
        if (A[i] > N) {
        }
    }

    // Check if Permutation
    bool is_perm = true;
    for (int i = 1; i <= N; ++i) {
        if (c[i] != 1) {
            is_perm = false;
            break;
        }
    }

    if (is_perm) {
        cout << 1 << endl;
        return;
    }

    // Identify v_max
    int v_max = -1;
    for (int i = N; i >= 1; --i) {
        if (c[i] > 1) {
            v_max = i;
            break;
        }
    }

    if (v_max == -1) {
        cout << 0 << endl; // Should not be reached properly
        return;
    }

    vector<int> candidates;
    for (int i = 1; i * i <= v_max; ++i) {
        if (v_max % i == 0) {
            if (i > 1) candidates.push_back(i);
            if (i * i != v_max) {
                if (v_max / i > 1) candidates.push_back(v_max / i);
            }
        }
    }

    long long total_ans = 0;


    vector<int> out_flow(N + 1);

    for (int X : candidates) {
        bool valid = true;
        long long current_ans = 1;


        for(int v = N; v >= 1; --v) {
            int in_flow = 0;
            long long vX = (long long)v * X;
            if (vX <= N) {
                in_flow = out_flow[vX];
            }

            int flow = c[v] + in_flow - 1;

            if (flow < 0 || flow > c[v]) {
                valid = false;
                break;
            }

            if (flow > 0) {
                if (v % X != 0) {
                    valid = false;
                    break;
                }
                out_flow[v] = flow;
                current_ans = (current_ans * nCr(c[v], flow)) % MOD;
            } else {
                out_flow[v] = 0;
                // nCr(c[v], 0) is 1
            }
        }

        if (valid) {
            if (out_flow[1] != 0) valid = false;
        }

        if (valid) {
            total_ans = (total_ans + current_ans) % MOD;
        }
    }

    cout << total_ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomputeFactorials(200005);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
