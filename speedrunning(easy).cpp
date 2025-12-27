#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;
    vector<int> A(N);
    vector<vector<int>> by_val(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        by_val[A[i]].push_back(i + 1); // 1-based indices
    }

    int K;
    cin >> K; // Q=1

    vector<int> current_P;
    long long total_ans = 0;

    for (int h = N; h >= 1; --h) {
        // Merge by_val[h] into current_P
        vector<int> next_P;
        next_P.reserve(current_P.size() + by_val[h].size());

        int i = 0, j = 0;
        while (i < current_P.size() && j < by_val[h].size()) {
            if (current_P[i] < by_val[h][j]) {
                next_P.push_back(current_P[i]);
                i++;
            } else {
                next_P.push_back(by_val[h][j]);
                j++;
            }
        }
        while (i < current_P.size()) next_P.push_back(current_P[i++]);
        while (j < by_val[h].size()) next_P.push_back(by_val[h][j++]);

        current_P = next_P;

        // Calculate contribution for height h
        long long h_cost = 0;

        // Base cost
        long long term1 = 0;
        for (int u : current_P) {
            term1 = (term1 + (long long)u * (N - u + 1)) % MOD;
        }
        term1 = (term1 * (K + 1)) % MOD;
        h_cost = (h_cost + term1) % MOD;

        // Savings
        long long term2 = 0;
        for (size_t k = 0; k + 1 < current_P.size(); ++k) {
            int u = current_P[k];
            int v = current_P[k+1];
            int gap = v - u - 1;
            if (gap < K) {
                long long saving = K - gap;
                long long ways = (long long)u * (N - v + 1) % MOD;
                term2 = (term2 + saving * ways) % MOD;
            }
        }

        h_cost = (h_cost - term2 + MOD) % MOD;
        total_ans = (total_ans + h_cost) % MOD;
    }

    cout << total_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}

