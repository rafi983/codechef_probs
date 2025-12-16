#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;
const int MAXN = 200005;

long long pow3[MAXN];
long long inv2;

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

void precompute() {
    pow3[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow3[i] = (pow3[i - 1] * 3) % MOD;
    }
    inv2 = power(2, MOD - 2);
}

long long sum_pow3(int C) {
    if (C == 0) return 0;
    long long num = (pow3[C] - 1 + MOD) % MOD;
    return (num * inv2) % MOD;
}

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> indices[3];
    indices[0].push_back(0); // P_0 = 0 at index 0 (representing i-1 = 0 -> i=1)


    int current_P = 0;
    long long total_ans = 0;

    for (int j = 1; j <= N; ++j) {
        current_P = (current_P + A[j-1]) % 3;

        int target = current_P;

        // Case 2: val = (target - 1)
        int val = (target - 1 + 3) % 3;
        int C = indices[val].size();
        if (C > 0) {
            long long term = sum_pow3(C);
            total_ans = (total_ans + term) % MOD;
        }

        // Case 3: val = (target - 2)
        val = (target - 2 + 3) % 3;
        C = indices[val].size();
        if (C > 0) {
            int last_occ = indices[val].back();
            int target_1 = (val + 1) % 3;

            auto it = upper_bound(indices[target_1].begin(), indices[target_1].end(), last_occ);

            if (it == indices[target_1].end()) {
                long long term = (2 * sum_pow3(C)) % MOD;
                total_ans = (total_ans + term) % MOD;
            } else {
                int z = indices[target_1].end() - it - 1;
                long long M = (1 + pow3[1 + z]) % MOD;
                long long term = (M * sum_pow3(C)) % MOD;
                total_ans = (total_ans + term) % MOD;
            }
        }

        indices[current_P].push_back(j);
    }

    cout << total_ans << "\n";
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

