#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

long long MOD = 998244353;

const int MAXN = 1 << 20; // 2^20
long long T_ways[MAXN + 5];

void precompute_ways() {
    T_ways[0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        // T(n) = n * T(n-1) + 1
        T_ways[i] = (i * T_ways[i - 1] + 1) % MOD;
    }
}

int get_popcount(int n) {
    return bitset<20>(n).count();
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    int start_val = A[0];
    int end_val = A[N - 1];
    int K = start_val ^ end_val;

    cout << K << " ";

    if (K == 0) {
        int count = 0;
        for (int i = 1; i < N - 1; ++i) {
            if (A[i] == start_val) count++;
        }
        cout << T_ways[count] << "\n";
        return;
    }

    vector<int> bits;
    for (int i = 0; i < 20; ++i) {
        if ((K >> i) & 1) bits.push_back(i);
    }

    int p = bits.size();
    int size = 1 << p;
    vector<int> C(size, 0);

    for (int i = 1; i < N - 1; ++i) {
        int val = A[i] ^ start_val;
        if ((val & ~K) == 0) {
            int mask = 0;
            for (int j = 0; j < p; ++j) {
                if ((val >> bits[j]) & 1) mask |= (1 << j);
            }
            C[mask]++;
        }
    }

    vector<long long> Mult(size);
    for (int m = 0; m < size; ++m) {
        if (m == 0 || m == size - 1) {
            Mult[m] = T_ways[C[m]];
        } else {
            Mult[m] = (T_ways[C[m]] - 1 + MOD) % MOD;
        }
    }

    vector<long long> S(size, 0);
    vector<long long> DP(size, 0);
    vector<long long> layer_DP(size, 0);

    // Layer 0
    DP[0] = Mult[0];
    layer_DP[0] = DP[0];

    // SOS for layer 0
    for (int i = 0; i < p; ++i) {
        for (int mask = 0; mask < size; ++mask) {
            if (mask & (1 << i)) {
                layer_DP[mask] = (layer_DP[mask] + layer_DP[mask ^ (1 << i)]) % MOD;
            }
        }
    }
    for(int m=0; m<size; ++m) S[m] = (S[m] + layer_DP[m]) % MOD;

    for (int k = 1; k <= p; ++k) {
        fill(layer_DP.begin(), layer_DP.end(), 0);
        bool any = false;

        for (int m = 0; m < size; ++m) {
            if (get_popcount(m) == k) {
                long long ways = (Mult[m] * S[m]) % MOD;
                DP[m] = ways;
                layer_DP[m] = ways;
                any = true;
            }
        }

        if (!any) continue;

        for (int i = 0; i < p; ++i) {
            for (int mask = 0; mask < size; ++mask) {
                if (mask & (1 << i)) {
                    layer_DP[mask] = (layer_DP[mask] + layer_DP[mask ^ (1 << i)]) % MOD;
                }
            }
        }

        for(int m=0; m<size; ++m) S[m] = (S[m] + layer_DP[m]) % MOD;
    }

    cout << DP[size - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute_ways();
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
